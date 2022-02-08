#pragma once
//store system time
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
class Date
{
private:
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    bool format;
    std::string AMPM;
public:
    Date();
    Date(int year, int month, int day, int hour, int minute, int second);
    Date(const Date&);
    ~Date();
    //setters
    void setSystemTime();
    void setYear(int year);
    void setMonth(int month);
    void setDay(int day);
    void setHour(int hour);
    void setMinute(int minute);
    void setSecond(int second);
    void setAMPM(std::string AMPM);
    //getters
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    int getHour() const;
    int getMinute() const;
    int getSecond() const;
    std::string getAMPM() const;
    bool getFormat() const;
    //print functions
    void print() const;
    void print(const std::string& fileName) const;
    void print(std::ofstream& out) const;
    //read functions
    void read(const std::string& fileName);
    void read(std::ifstream& in);
    void read(std::istream& in);
    //operator overloads
    Date& operator=(const Date&);
    Date& operator+=(const Date&);
    Date& operator+=(const int&);
    Date& operator-=(const Date&);
    Date& operator-=(const int&);
    Date& operator+(const Date&) const;
    Date& operator+(const int&) const;
    Date& operator-(const Date&) const;
    Date& operator-(const int&) const;
    Date& operator++();
    Date& operator--();
    Date& operator++(int);
    Date& operator--(int);
    bool operator==(const Date&) const;
    bool operator!=(const Date&) const;
    bool operator<(const Date&) const;
    bool operator>(const Date&) const;
    bool operator<=(const Date&) const;
    bool operator>=(const Date&) const;
    //conversion operator overloads
    operator int() const;
    operator std::string() const;
    operator std::tm() const;
    //extraction operator overloads
    friend std::istream& operator>>(std::istream& in, Date& date);
    friend std::ostream& operator<<(std::ostream& out, const Date& date);
    friend std::ofstream& operator>>(std::ofstream& out, const Date& date);
    friend std::ifstream& operator>>(std::ifstream& in, Date& date);
    //convert to string
    std::string toString() const;
    //convert to 24 hour time
    Date to24Hour();
    //convert to 12 hour time
    Date to12Hour();
};