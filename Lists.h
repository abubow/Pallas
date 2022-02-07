#ifndef LIST_H
#define LIST_H
#pragma once
#include <iostream>
#include <fstream>
#include <string>
template <typename T>
class Lists
{
protected:
    T* list;
    int size;
    int capacity;
public:
    Lists();
    Lists(const Lists&);
    Lists(const T* list, int size);
    ~Lists();
    //adders and removers
    void add(const T&);
    void add(const T*, int);
    void add(const Lists&);
    void remove(const T&);
    void remove(const T*, int);
    void remove(const Lists&);
    //getters
    const T* getList() const;
    int getSize() const;
    int getCapacity() const;
    T& get(int index) const;
    //setters
    void setList(const T* list);
    void setSize(int size);
    void setCapacity(int capacity);
    void set(int index, const T&);
    //print functions
    void print() const;
    void print(int index) const;
    void print(const std::string& fileName) const;
    void print(std::ofstream& out) const;
    //read functions
    void read(const std::string& fileName);
    void read(std::ifstream& in);
    void read(std::istream& in);
    //operator overloads
    Lists& operator=(const Lists&);
    Lists& operator+=(const Lists&);
    Lists& operator+=(const T* list);
    Lists& operator+=(const T&);
    Lists& operator-=(const Lists&);
    Lists& operator-=(const T* list);
    Lists& operator-=(const T&);
    Lists& operator+(const Lists&) const;
    Lists& operator+(const T* list) const;
    Lists& operator+(const T&) const;
    Lists& operator-(const Lists&) const;
    Lists& operator-(const T* list) const;
    Lists& operator-(const T&) const;
    bool operator==(const Lists&) const;
    bool operator!=(const Lists&) const;
    T& operator[](int index) const;
    //extraction operator overloads
    friend std::ostream& operator<<(std::ostream& out, const Lists& list);
    friend std::ofstream& operator<<(std::ofstream& out, const Lists& list);
    //insertion operator overloads
    friend std::istream& operator>>(std::istream& in, Lists& list);
    friend std::ifstream& operator>>(std::ifstream& in, Lists& list);
    //search functions
    bool search(const T&) const;
    bool search(const T*, int) const;
    bool search(const Lists&) const;
    //other functions
    void sort();
    void sort(int start, int end);
    void clear();
    void resize(int newCapacity);
    void resize(int newCapacity, const T&);
    bool isEmpty() const;
    bool isFull() const;
    void reverse();
    void reverse(int start, int end);
    bool isSorted() const;
    bool isSorted(int start, int end) const;
    void merge(const Lists&);
    void merge(const Lists&, int start, int end);
};
#endif // !LIST_H