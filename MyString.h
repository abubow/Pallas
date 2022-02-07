#ifndef MYSTRING_H
#define MYSTRING_H
#pragma once
#include <iostream>
#include <fstream>
class MyString
{
private:
    char* str;
    int size;
public:
    MyString(){
        str = nullptr;
        size = 0;
    }
    MyString(const char* str){
        size = strlen(str);
        this->str = new char[size + 1];
        strcpy_s(this->str, size, str);
    }
    MyString(const MyString& str){
        size = str.size;
        this->str = new char[size + 1];
        strcpy_s(this->str, size, str.str);
    }
    MyString(const std::string& str){
        size = str.size();
        this->str = new char[size + 1];
        strcpy_s(this->str, size, str.c_str());
    }
    ~MyString(){
        delete[] str;
    }
    //sort functions
    void sort(){
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size - 1; j++){
                if(str[j] > str[j + 1]){
                    char temp = str[j];
                    str[j] = str[j + 1];
                    str[j + 1] = temp;
                }
            }
        }
    }
    void sort(int start, int end){
        for(int i = start; i < end; i++){
            for(int j = start; j < end - 1; j++){
                if(str[j] > str[j + 1]){
                    char temp = str[j];
                    str[j] = str[j + 1];
                    str[j + 1] = temp;
                }
            }
        }
    }
    bool isSorted(){
        for(int i = 0; i < size - 1; i++){
            if(str[i] > str[i + 1]){
                return false;
            }
        }
        return true;
    }
    bool isSorted(int start, int end){
        for(int i = start; i < end - 1; i++){
            if(str[i] > str[i + 1]){
                return false;
            }
        }
        return true;
    }
    //search functions
    bool search(const char& c){
        for(int i = 0; i < size; i++){
            if(str[i] == c){
                return true;
            }
        }
        return false;
    }
    bool search(const char* str){
        bool found = false;
        int i = 0;
        while(!found && i < size){
            int j = 0;
            while(!found && j < strlen(str) && i + j < size){
                if(str[j] == str[i + j]){
                    j++;
                }
                else{
                    found = false;
                    break;
                }
                if(j == strlen(str)){
                    found = true;
                }
            }
            i++;
        }
    }
    bool search(const MyString& str){
        return search(str.str);
    }
    bool search(const std::string& str){
        return search(str.c_str());
    }
    //other functions
    void clear(){
        delete[] str;
        str = nullptr;
        size = 0;
    }
    void clear(int start, int end){
        for(int i = start; i < end; i++){
            str[i] = '\0';
        }
    }
    void clear(int start){
        for(int i = start; i < size; i++){
            str[i] = '\0';
        }
    }
    void clear(int start, int end, char c){
        for(int i = start; i < end; i++){
            str[i] = c;
        }
    }
    void remove(int start, int end){
        for(int i = start; i < end; i++){
            str[i] = '\0';
        }
    }
    void regrow(int newSize){
        char* temp = new char[newSize + 1];
        for(int i = 0; i < size; i++){
            temp[i] = str[i];
        }
        delete[] str;
        str = temp;
        size = newSize;
    }
    bool isEmpty(){
        return size == 0;
    }
    int getSize() const
    {
        return size;
    }
    char* getStr(){
        return str;
    }
    char getChar(int index){
        return str[index];
    }
    void setChar(int index, char c){
        str[index] = c;
    }
    void setStr(const char* str){
        delete[] this->str;
        size = strlen(str);
        this->str = new char[size + 1];
        strcpy_s(this->str,size, str);
    }
    void setStr(const MyString& str){
        delete[] this->str;
        size = str.size;
        this->str = new char[size + 1];
        strcpy_s(this->str, size, str.str);
    }
    void setStr(const std::string& str){
        delete[] this->str;
        size = str.size();
        this->str = new char[size + 1];
        strcpy_s(this->str,size, str.c_str());
    }
    void remove(char toRemove){
        char* temp = new char[size - 1];
        int i = 0;
        for(int j = 0; j < size; j++){
            if(str[j] != toRemove){
                temp[i] = str[j];
                i++;
            }
        }
        delete[] str;
        str = temp;
        size--;
    }
    MyString& operator=(const MyString& str){
        if(this != &str){
            delete[] this->str;
            size = str.size;
            this->str = new char[size + 1];
            strcpy_s(this->str, size, str.str);
        }
        return *this;
    }
    MyString& operator=(const char* str){
        delete[] this->str;
        size = strlen(str);
        this->str = new char[size + 1];
        strcpy_s(this->str, size, str);
        return *this;
    }
    MyString& operator=(const std::string& str){
        *this = str.c_str();
        return *this;
    }
    MyString& operator+=(const MyString& str){
        *this += str.str;
        return *this;
    }
    MyString& operator+=(const char* str){
        int newSize = size + strlen(str);
        char* newStr = new char[newSize + 1];
        strcpy_s(newStr, size, this->str);
        strcat_s(newStr, strlen(str), str);
        delete[] this->str;
        this->str = newStr;
        size = newSize;
        return *this;
    }
    MyString& operator+=(const std::string& str){
        *this += str.c_str();
        return *this;
    }
    /*
    MyString& operator-=(const MyString& str){
        *this -= str.str;
        return *this;
    }
    MyString& operator-=(const char* str){
        int newSize = size - strlen(str);
        char* newStr = new char[newSize + 1];
        strcpy_s(newStr, size, this->str);
        strcat_s(newStr, str);
        delete[] this->str;
        this->str = newStr;
        size = newSize;
        return *this;
    }
    MyString& operator-=(const std::string& str){
        *this -= str.c_str();
        return *this;
    }
    MyString& operator*=(const MyString& str){
        *this *= str.str;
        return *this;
    }
    MyString& operator*=(const char* str){
        int newSize = size * strlen(str);
        char* newStr = new char[newSize + 1];
        strcpy(newStr, this->str);
        strcat_s(newStr, str);
        delete[] this->str;
        this->str = newStr;
        size = newSize;
        return *this;
    }
    MyString& operator*=(const std::string& str){
        *this *= str.c_str();
        return *this;
    }
    MyString& operator/=(const MyString& str){
        *this /= str.str;
        return *this;
    }
    MyString& operator/=(const char* str){
        int newSize = size / strlen(str);
        char* newStr = new char[newSize + 1];
        strcpy(newStr, this->str);
        strcat_s(newStr, str);
        delete[] this->str;
        this->str = newStr;
        size = newSize;
        return *this;
    }
    MyString& operator/=(const std::string& str){
        *this /= str.c_str();
        return *this;
    }
    MyString& operator++(){
        *this += "1";
        return *this;
    }
    MyString& operator--(){
        *this -= "1";
        return *this;
    }
    MyString& operator++(int){
        MyString tmp(*this);
        *this += "1";
        return tmp;
    }
    MyString& operator--(int){
        MyString tmp(*this);
        *this -= "1";
        return tmp;
    }
    MyString operator-(const MyString& str){
        MyString tmp(*this);
        tmp -= str;
        return tmp;
    }
    MyString operator-(const char* str){
        MyString tmp(*this);
        tmp -= str;
        return tmp;
    }
    MyString operator-(const std::string& str){
        MyString tmp(*this);
        tmp -= str;
        return tmp;
    }
    MyString operator*(const MyString& str){
        MyString tmp(*this);
        tmp *= str;
        return tmp;
    }
    MyString operator*(const char* str){
        MyString tmp(*this);
        tmp *= str;
        return tmp;
    }
    MyString operator*(const std::string& str){
        MyString tmp(*this);
        tmp *= str;
        return tmp;
    }
    MyString operator/(const MyString& str){
        MyString tmp(*this);
        tmp /= str;
        return tmp;
    }
    MyString operator/(const char* str){
        MyString tmp(*this);
        tmp /= str;
        return tmp;
    }
    MyString operator/(const std::string& str){
        MyString tmp(*this);
        tmp /= str;
        return tmp;
    }
    */
    MyString operator+(const MyString& str){
        MyString tmp(*this);
        tmp += str;
        return tmp;
    }
    MyString operator+(const char* str){
        MyString tmp(*this);
        tmp += str;
        return tmp;
    }
    MyString operator+(const std::string& str){
        MyString tmp(*this);
        tmp += str;
        return tmp;
    }
    bool operator==(const MyString& str){
        return strcmp(this->str, str.str) == 0;
    }
    bool operator==(const char* str){
        return strcmp(this->str, str) == 0;
    }
    bool operator==(const std::string& str){
        return strcmp(this->str, str.c_str()) == 0;
    }
    bool operator!=(const MyString& str){
        return !(*this == str);
    }
    bool operator!=(const char* str){
        return !(*this == str);
    }
    bool operator!=(const std::string& str){
        return !(*this == str);
    }
    bool operator<(const MyString& str){
        return strcmp(this->str, str.str) < 0;
    }
    bool operator<(const char* str){
        return strcmp(this->str, str) < 0;
    }
    bool operator<(const std::string& str){
        return strcmp(this->str, str.c_str()) < 0;
    }
    bool operator>(const MyString& str){
        return strcmp(this->str, str.str) > 0;
    }
    bool operator>(const char* str){
        return strcmp(this->str, str) > 0;
    }
    bool operator>(const std::string& str){
        return strcmp(this->str, str.c_str()) > 0;
    }
    bool operator<=(const MyString& str){
        return strcmp(this->str, str.str) <= 0;
    }
    bool operator<=(const char* str){
        return strcmp(this->str, str) <= 0;
    }
    bool operator<=(const std::string& str){
        return strcmp(this->str, str.c_str()) <= 0;
    }
    bool operator>=(const MyString& str){
        return strcmp(this->str, str.str) >= 0;
    }
    bool operator>=(const char* str){
        return strcmp(this->str, str) >= 0;
    }
    bool operator>=(const std::string& str){
        return strcmp(this->str, str.c_str()) >= 0;
    }
    char& operator[](int index){
        return str[index];
    }
    const char& operator[](int index) const{
        return str[index];
    }
    friend std::ostream& operator<<(std::ostream& os, const MyString& str){
        os << str.str;
        return os;
    }
    friend std::istream& operator>>(std::istream& is, MyString& str){
        char* tmp = new char[str.size + 1];
        is >> tmp;
        delete[] str.str;
        str.str = tmp;
        return is;
    }
    friend std::ifstream& operator>>(std::ifstream& is, MyString& str){
        char* tmp = new char[str.size + 1];
        is >> tmp;
        delete[] str.str;
        str.str = tmp;
        return is;
    }
    friend std::ofstream& operator<<(std::ofstream& os, const MyString& str){
        os << str.str;
        return os;
    }
    friend std::fstream& operator<<(std::fstream& os, const MyString& str){
        os << str.str;
        return os;
    }
    friend std::istream& getline(std::istream& is, MyString& str){
        char* tmp = new char[str.size + 1];
        is.getline(tmp, str.size + 1);
        delete[] str.str;
        str.str = tmp;
        return is;
    }
    friend std::ifstream& getline(std::ifstream& is, MyString& str){
        char* tmp = new char[str.size + 1];
        is.getline(tmp, str.size + 1);
        delete[] str.str;
        str.str = tmp;
        return is;
    }
    friend std::ofstream& getline(std::ofstream& os, const MyString& str){
        os << str.str;
        return os;
    }
    friend std::fstream& getline(std::fstream& os, const MyString& str){
        os << str.str;
        return os;
    }
    friend std::istream& getline(std::istream& is, MyString& str, char delim){
        char* tmp = new char[str.size + 1];
        is.getline(tmp, str.size + 1, delim);
        delete[] str.str;
        str.str = tmp;
        return is;
    }
    friend std::ifstream& getline(std::ifstream& is, MyString& str, char delim){
        char* tmp = new char[str.size + 1];
        is.getline(tmp, str.size + 1, delim);
        delete[] str.str;
        str.str = tmp;
        return is;
    }
    friend std::ofstream& getline(std::ofstream& os, const MyString& str, char delim){
        os << str.str;
        return os;
    }
    friend std::fstream& getline(std::fstream& os, const MyString& str, char delim){
        os << str.str;
        return os;
    }  
};
#endif // MYSTRING_H