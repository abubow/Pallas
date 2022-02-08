#include "Date.h"

Date::Date(){
    day = 0;
    month = 0;
    year = 0;
    hour = 0;
    minute = 0;
    second = 0;
    format = false;
}

Date::Date(int year, int month, int day, int hour, int minute, int second){
    this->day = day;
    this->month = month;
    this->year = year;
    this->hour = hour;
    this->minute = minute;
    this->second = second;
    this->format = false;  
    this->AMPM = "AM";
}

Date::Date(const Date& date){
    this->day = date.day;
    this->month = date.month;
    this->year = date.year;
    this->hour = date.hour;
    this->minute = date.minute;
    this->second = date.second;
    this->format = date.format;
    this->AMPM = date.AMPM;
}

Date::~Date(){

}

void Date::setSystemTime(){
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    this->day = now->tm_mday;
    this->month = now->tm_mon + 1;
    this->year = now->tm_year + 1900;
    this->hour = now->tm_hour;
    this->minute = now->tm_min;
    this->second = now->tm_sec;
    delete now;
}

//setters
void Date::setYear(int year){
    this->year = year;
}
void Date::setMonth(int month){
    this->month = month;
}
void Date::setDay(int day){
    this->day = day;
}
void Date::setHour(int hour){
    this->hour = hour;
}
void Date::setMinute(int minute){
    this->minute = minute;
}
void Date::setSecond(int second){
    this->second = second;
}
void Date::setAMPM(std::string AMPM){
    this->AMPM = AMPM;
}

//getters
int Date::getYear() const{
    return year;
}
int Date::getMonth() const{
    return month;
}
int Date::getDay() const{
    return day;
}
int Date::getHour() const{
    return hour;
}
int Date::getMinute() const{
    return minute;
}
int Date::getSecond() const{
    return second;
}
std::string Date::getAMPM() const{
    return AMPM;
}
bool Date::getFormat() const{
    return format;
}

//print functions
void Date::print() const{
    std::cout << "Date: " << year << "-" << month << "-" << day << " " << hour << ":" << minute << ":" << second << " " << AMPM << std::endl;
}
void Date::print(const std::string& fileName) const{
    std::ofstream out(fileName);
    out << "Date: " << year << "-" << month << "-" << day << " " << hour << ":" << minute << ":" << second << " " << AMPM << std::endl;
    out.close();
}
void Date::print(std::ofstream& out) const{
    out << "Date: " << year << "-" << month << "-" << day << " " << hour << ":" << minute << ":" << second << " " << AMPM << std::endl;
}
//read functions
void Date::read(const std::string& fileName){
    // time format is:
    // Date: year-month-day hour:minute:second
    std::ifstream in(fileName);
    read(in);
    in.close();
}
void Date::read(std::ifstream& in){
    // time format is:
    // Date: year-month-day hour:minute:second AM/PM
    std::stringstream ss;
    std::string line;
    std::getline(in, line);
    ss << line;
    ss >> this->year;
    ss.ignore();
    ss >> this->month;
    ss.ignore();
    ss >> this->day;
    ss.ignore();
    ss >> this->hour;
    ss.ignore();
    ss >> this->minute;
    ss.ignore();
    ss >> this->second;
    ss.ignore();
    ss >> this->AMPM;
    ss.ignore();
    if(this->AMPM == "PM"){
        this->hour += 12;
    }
    this->format = true;
    in.close();
}
void Date::read(std::istream& in){
    // time format is:
    // Date: year-month-day hour:minute:second
    in >> *this;
}
//operators
Date& Date::operator=(const Date& date){
    this->day = date.day;
    this->month = date.month;
    this->year = date.year;
    this->hour = date.hour;
    this->minute = date.minute;
    this->second = date.second;
    this->format = date.format;
    this->AMPM = date.AMPM;
    return *this;
}
bool Date::operator==(const Date& date) const
{
    bool isEqual = false;
    if( this->day == date.day && 
        this->month == date.month &&
        this->year == date.year &&
        this->hour == date.hour &&
        this->minute == date.minute &&
        this->second == date.second &&
        this->AMPM == date.AMPM &&
        this->format == date.format){
        isEqual = true;
    }
    return isEqual;
}
bool Date::operator!=(const Date& date) const
{
    return !(*this == date);
}
Date& Date::operator+=(const Date& date){
    this->day += date.day;
    this->month += date.month;
    this->year += date.year;
    this->hour += date.hour;
    this->minute += date.minute;
    this->second += date.second;
    this->AMPM = date.AMPM;
    return *this;
}
Date& Date::operator+= (const int& days){
    this->day += days;
    return *this;
}
Date& Date::operator-=(const Date& date){
    this->day -= date.day;
    this->month -= date.month;
    this->year -= date.year;
    this->hour -= date.hour;
    this->minute -= date.minute;
    this->second -= date.second;
    return *this;
}
Date& Date::operator-= (const int& days){
    this->day -= days;
    return *this;
}
Date& Date::operator++(){
    this->day++;
    this->month++;
    this->year++;
    this->hour++;
    this->minute++;
    this->second++;
    return *this;
}
Date& Date::operator--(){
    this->day--;
    this->month--;
    this->year--;
    this->hour--;
    this->minute--;
    this->second--;
    return *this;
}
Date& Date::operator++(int){
    Date temp(*this);
    this->day++;
    this->month++;
    this->year++;
    this->hour++;
    this->minute++;
    this->second++;
    return temp;
}
Date& Date::operator--(int){
    Date temp(*this);
    this->day--;
    this->month--;
    this->year--;
    this->hour--;
    this->minute--;
    this->second--;
    return temp;
}
Date& Date::operator+(const Date& date) const{
    Date temp(*this);
    temp += date;
    return temp;
}
Date& Date::operator+(const int& days) const{
    Date temp(*this);
    temp += days;
    return temp;
}
Date& Date::operator-(const Date& date) const{
    Date temp(*this);
    temp -= date;
    return temp;
}
Date& Date::operator-(const int& days) const{
    Date temp(*this);
    temp -= days;
    return temp;
}
bool Date::operator<(const Date& date) const{
    bool isLess = false;
    if(this->year < date.year){
        isLess = true;
    }
    else if(this->year == date.year){
        if(this->month < date.month){
            isLess = true;
        }
        else if(this->month == date.month){
            if(this->day < date.day){
                isLess = true;
            }
            else if(this->day == date.day){
                if(this->hour < date.hour){
                    isLess = true;
                }
                else if(this->hour == date.hour){
                    if(this->minute < date.minute){
                        isLess = true;
                    }
                    else if(this->minute == date.minute){
                        if(this->second < date.second){
                            isLess = true;
                        }
                    }
                }
            }
        }
    }
    return isLess;
}
bool Date::operator>(const Date& date) const{
    return !(*this == date) && !(*this < date);
}
bool Date::operator<=(const Date& date) const{
    return (*this < date) || (*this == date);
}
bool Date::operator>=(const Date& date) const{
    return (*this > date) || (*this == date);
}
//converters
Date::operator std::string() const{
    std::stringstream ss;
    ss << "Date: " << year << "-" << month << "-" << day << " " << hour << ":" << minute << ":" << second << " " << AMPM;
    return ss.str();
}
Date::operator std::tm() const{
    std::tm temp;
    temp.tm_year = year - 1900;
    temp.tm_mon = month - 1;
    temp.tm_mday = day;
    temp.tm_hour = hour;
    temp.tm_min = minute;
    temp.tm_sec = second;
    return temp;
}
Date::operator int() const{
    return (year * 10000) + (month * 100) + day;
}
std::ostream& operator<<(std::ostream& out, const Date& date){
    out << "Date: " << date.year << "-" << date.month << "-" << date.day << " " << date.hour << ":" << date.minute << ":" << date.second << " " << date.AMPM << std::endl;
    return out;
}
std::istream& operator>>(std::istream& in, Date& date){
    // time format is:
    // Date: year-month-day hour:minute:second PM/AM
    std::stringstream ss;
    std::string line;
    std::getline(in, line);
    int x = 0;
    ss << line;
    ss >> x;
    ss.ignore();
    date.setYear(x);
    ss >> x;
    ss.ignore();
    date.setMonth(x);
    ss >> x;
    ss.ignore();
    date.setDay(x);
    ss >> x;
    ss.ignore();
    date.setHour(x);
    ss >> x;
    ss.ignore();
    date.setMinute(x);
    ss >> x;
    ss.ignore();
    date.setSecond(x);
    ss >> line;
    ss.ignore();
    date.setAMPM(line);

    return in;
}
std::ifstream& operator>>(std::ifstream& in, Date& date){
    // time format is:
    // Date: year-month-day hour:minute:second PM/AM
    date.read(in);
    return in;
}
std::ofstream& operator>>(std::ofstream& out, const Date& date){
        out << "Date: " << date.getYear() << "-" << date.getMonth() << "-" << date.getDay() << " " << date.getHour() << ":" << date.getMinute() << ":" << date.getSecond() << " " << date.getAMPM() << std::endl;
    return out;
}

//conversion functions
std::string Date::toString() const{
    std::stringstream ss;
    ss << "Date: " << year << "-" << month << "-" << day << " " << hour << ":" << minute << ":" << second << " " << AMPM;
    return ss.str();
}
//convert to 12 hour format
Date Date::to12Hour(){
    Date temp(*this);
    int hour = temp.getHour();
    int minute = temp.getMinute();
    int second = temp.getSecond();
    format = true;
    bool isPM = false;
    while (hour > 12){
        hour -= 12;
        isPM = !isPM;
    }
    while (minute>60){
        minute -= 60;
        hour++;
    }
    while (second>60){
        second -= 60;
        minute++;
    }
    if (isPM){
        temp.setHour(hour);
        temp.setMinute(minute);
        temp.setSecond(second);
        temp.setAMPM("PM");
    }
    else{
        temp.setHour(hour);
        temp.setMinute(minute);
        temp.setSecond(second);
        temp.setAMPM("AM");
    }
    return temp;
}
//convert to 24 hour format
Date Date::to24Hour(){
    Date temp(*this);
    int hour = temp.getHour();
    int minute = temp.getMinute();
    int second = temp.getSecond();
    bool isPM = false;
    format = false;
    while (hour > 12){
        hour -= 12;
        isPM = !isPM;
    }
    while (minute>60){
        minute -= 60;
        hour++;
    }
    while (second>60){
        second -= 60;
        minute++;
    }
    if (isPM){
        temp.setHour(hour+12);
        temp.setMinute(minute);
        temp.setSecond(second);
    }
    else{
        temp.setHour(hour);
        temp.setMinute(minute);
        temp.setSecond(second);
    }
    return temp;
}

