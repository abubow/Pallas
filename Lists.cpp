#include "Lists.h"

//implementation of Lists.h

template <class T>
Lists<T>::Lists()
{
	list = nullptr;
	size = 0;
	capacity = 0;
}

template <class T>
Lists<T>::Lists(const Lists& list)
{
	this->size = list.size;
	this->capacity = list.capacity;
	this->list = new T[capacity];
	for (int i = 0; i < size; i++)
	{
		this->list[i] = list.list[i];
	}
}

template <class T>
Lists<T>::Lists(const T* list, int size)
{
	if (size < 0)
    {
        throw std::invalid_argument("size must be greater than 0");
    }
    if (list == nullptr)
    {
        throw std::invalid_argument("list cannot be null");
    }
    this->size = size;
    this->capacity = size;
    this->list = new T[capacity];
    for (int i = 0; i < size; i++)
    {
        this->list[i] = list[i];
    }
}

template <class T>
Lists<T>::~Lists()
{
	delete[] list;
}

//adders and removers

template <class T>
void Lists<T>::add(const T& item)
{
	if (size == capacity)
	{
		resize(capacity + 1);
	}
	list[size] = item;
	size++;
}

template <class T>
void Lists<T>::add(const T* list, int size)
{
	for (int i = 0; i < size; i++)
	{
		add(list[i]);
	}
}

template <class T>
void Lists<T>::add(const Lists& list)
{
    if (size + list.size > capacity)
    {
        resize(size + list.size);
    }
    if (list.size > 0)
    {
        for (int i = 0; i < list.size; i++)
        {
            add(list.list[i]);
        }
    }
}

template <class T>
void Lists<T>::remove(const T& item)
{
	for (int i = 0; i < size; i++)
	{
		if (list[i] == item)
		{
			list[i] = list[size - 1];
            size--;
            break;
        }
    }
}

template <class T>
void Lists<T>::remove(const T* list, int size)
{
    for (int i = 0; i < size; i++)
    {
        remove(list[i]);
    }
}

template <class T>
void Lists<T>::remove(const Lists& list)
{
    for (int i = 0; i < list.size; i++)
    {
        remove(list.list[i]);
    }
}

//getters

template <class T>
const T* Lists<T>::getList() const
{
    return list;
}

template <class T>
int Lists<T>::getSize() const
{
    return size;
}

template <class T>
int Lists<T>::getCapacity() const
{
    return capacity;
}

template <class T>
T& Lists<T>::get(int index) const
{
    return list[index];
}

//setters

template <class T>
void Lists<T>::setList(const T* list)
{
    this->list = list;
}

template <class T>
void Lists<T>::setSize(int size)
{
    if (size > capacity)
    {
        resize(size);
    }
    if (size < capacity)
    {
        for (int i = size; i < capacity; i++)
        {
            list[i] = 0;
        }
    }
    this->size = size;
}

template <class T>
void Lists<T>::setCapacity(int capacity)
{
    if (capacity > this->capacity)
    {
        T* temp = new T[capacity];
        for (int i = 0; i < this->size; i++)
        {
            temp[i] = list[i];
        }
        delete[] list;
        list = temp;
        this->capacity = capacity;
    }
    else if (capacity < this->capacity)
    {
        T* temp = new T[capacity];
        for (int i = 0; i < capacity; i++)
        {
            temp[i] = list[i];
        }
        delete[] list;
        list = temp;
        this->capacity = capacity;
    }
    else 
    {
        this->capacity = capacity;
    }
}

template <class T>
void Lists<T>::set(int index, const T& item)
{
    list[index] = item;
}

//print functions
template <class T>
void Lists<T>::print() const
{
    for (int i = 0; i < size; i++)
    {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;
}

template <class T>
void Lists<T>::print(int index) const
{
    std::cout << list[index] << std::endl;
}

template <class T>
void Lists<T>::print(const std::string& filename) const
{
    std::ofstream file;
    file.open(filename);
    for (int i = 0; i < size; i++)
    {
        file << (*this)[i] << " ";
    }
    file.close();
}

template <class T>
void Lists<T>::print(std::ofstream& out) const{
    for (int i = 0; i < size; i++)
    {
        out << list[i] << " ";
    }
}

//read functions
template <class T>
void Lists<T>::read(const std::string& filename)
{
    std::ifstream file;
    file.open(filename);
    if (file.is_open())
    {
        int size = 0;
        file >> size;
        resize(size);
        for (int i = 0; i < size; i++)
        {
            file >> list[i];
        }
        file.close();
    }
    else
    {
        std::cerr << "File named " << filename << " could not be opened." << std::endl;
    }
}

template <class T>
void Lists<T>::read(std::ifstream& in)
{
    int size = 0;
    in >> size;
    resize(size);
    for (int i = 0; i < size; i++)
    {
        in >> list[i];
    }
}

template <class T>
void Lists<T>::read(std::istream& in)
{
    int size = 0;
    in >> size;
    resize(size);
    for (int i = 0; i < size; i++)
    {
        in >> list[i];
    }
}

//operator overloads
template <class T>
Lists<T>& Lists<T>::operator=(const Lists& list)
{
    if (this != &list)
    {
        delete[] list.list;
        this->size = list.size;
        this->capacity = list.capacity;
        this->list = new T[capacity];
        for (int i = 0; i < size; i++)
        {
            this->list[i] = list.list[i];
        }
    }
    return *this;
}

template <class T>
bool Lists<T>::operator==(const Lists& list) const
{
    if (this->size != list.size)
    {
        return false;
    }
    for (int i = 0; i < size; i++)
    {
        if (this->list[i] != list.list[i])
        {
            return false;
        }
    }
    return true;
}

template <class T>
bool Lists<T>::operator!=(const Lists& list) const
{
    return !(*this == list);
}

template <class T>
T& Lists<T>::operator[](int index) const
{
    if (index < 0 || index >= size)
    {
        throw std::out_of_range("Index out of range");
    }
    return list[index];
}

//extraction operator overloads
template <class T>
std::ostream& operator<<(std::ostream& out, const Lists<T>& list)
{
    list.print(out);
    return out;
}

template <class T>
std::ofstream& operator<<(std::ofstream& out, const Lists<T>& list)
{
    list.print(out);
    return out;
}

//insertion operator overloads
template <class T>
std::istream& operator>>(std::istream& in, Lists<T>& list)
{
    list.read(in);
    return in;
}

template <class T>
std::ifstream& operator>>(std::ifstream& in, Lists<T>& list)
{
    list.read(in);
    return in;
}

//search functions
template <class T>
bool Lists<T>::search(const T& item) const
{
    for (int i = 0; i < size; i++)
    {
        if (list[i] == item)
        {
            return true;
        }
    }
    return false;
}

template <class T>
bool Lists<T>::search(const T* list, int a) const
{
    for (int i = 0; i < a; i++)
    {
        if (this->list[i] == list[i])
        {
            return true;
        }
    }
    return false;
}

template <class T>
bool Lists<T>::search(const Lists<T>& list) const
{
    bool found = true;
    if (this->size != list.size)
    {
        return false;
    }
    for (int i = 0; i < list.size; i++)
    {
        if (!search(list[i]))
        {
            found = false;
        }
    }
    return found;
}

//other functions
//sort functions
template <class T>
void Lists<T>::sort()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (list[j] > list[j + 1])
            {
                T temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

template <class T>
bool Lists<T>::isSorted() const
{
    for (int i = 0; i < size - 1; i++)
    {
        if (list[i] > list[i + 1])
        {
            return false;
        }
    }
    return true;
}

template <class T>
bool Lists<T>::isSorted(int start, int end) const
{
    if (start < 0 || start >= size || end < 0 || end >= size)
    {
        throw std::out_of_range("Index out of range");
    }
    for (int i = start; i < end; i++)
    {
        if (list[i] > list[i + 1])
        {
            return false;
        }
    }
    return true;
}

template <class T>
void Lists<T>::sort(int start, int end)
{
    if (start < 0 || start >= size || end < 0 || end >= size)
    {
        throw std::out_of_range("Index out of range");
    }
    for (int i = start; i < end; i++)
    {
        for (int j = start; j < end - 1; j++)
        {
            if (list[j] > list[j + 1])
            {
                T temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

template <class T>
void Lists<T>::clear()
{
    if (list != nullptr)
    {
        delete[] list;
        list = nullptr;
        size = 0;
        capacity = 0;
    }
    else
    {
        throw std::out_of_range("List is empty");
    }
}

template <class T>
void Lists<T>::resize(int newCapacity)
{
    if (newCapacity < 0)
    {
        throw std::invalid_argument("Capacity must be greater than 0\n");
    }
    T* temp = new T[newCapacity];
    for (int i = 0; i < size; i++)
    {
        temp[i] = list[i];
    }
    delete[] list;
    list = temp;
    capacity = newCapacity;
}

template <class T>
void Lists<T>::resize(int newCapacity, const T& item)
{
    if (newCapacity < 0)
    {
        throw std::invalid_argument("Capacity must be greater than 0\n");
    }
    if (newCapacity < size)
    {
        throw std::invalid_argument("New capacity must be greater than or equal to the current size\n");
    }
    T* temp = new T[newCapacity];
    for (int i = 0; i < size; i++)
    {
        temp[i] = list[i];
    }
    for (int i = size; i < newCapacity; i++)
    {
        temp[i] = item;
    }
    delete[] list;
    list = temp;
    capacity = newCapacity;
}

template <class T>
bool Lists<T>::isEmpty() const
{
    return size == 0;
}

template <class T>
bool Lists<T>::isFull() const
{
    return size == capacity;
}

template <class T>
void Lists<T>::merge(const Lists& other)
{
    if (other.size == 0)
    {
        return;
    }
    if (size == 0)
    {
        *this = other;
        return;
    }
    if (size + other.size > capacity)
    {
        resize(size + other.size);
    }
    for (int i = size; i < size + other.size; i++)
    {
        list[i] = other[i - size];
    }
    size += other.size;
}

template <class T>
void Lists<T>::merge(const Lists& other, int start, int end)
{
    if (other.size == 0)
    {
        return;
    }
    if (size == 0)
    {
        *this = other;
        return;
    }
    if (size + other.size > capacity)
    {
        resize(size + other.size);
    }
    int i = size;
    for (int j = start; j < end; j++)
    {
        list[i] = other[j];
        i++;
    }
    size += other.size;
}
//reverse functions
template <class T>
void Lists<T>::reverse()
{
    for (int i = 0; i < size / 2; i++)
    {
        T temp = list[i];
        list[i] = list[size - 1 - i];
        list[size - 1 - i] = temp;
    }
}

template <class T>
void Lists<T>::reverse(int start, int end)
{
    if (start < 0 || start >= size || end < 0 || end >= size)
    {
        throw std::out_of_range("Index out of range");
    }
    for (int i = start; i < (start + end) / 2; i++)
    {
        T temp = list[i];
        list[i] = list[end - 1 - i + start];
        list[end - 1 - i + start] = temp;
    }
}

//arithmetic operators overloading
template <class T>
Lists<T>& Lists<T>::operator+=(const Lists<T>& other)
{
    add(other);
    return *this;
}

template <class T>
Lists<T>& Lists<T>::operator+=(const T& item)
{
    add(item);
}

template <class T>
Lists<T>& Lists<T>::operator+= (const T* items)
{
    add(items);
    return *this;
}

template <class T>
Lists<T>& Lists<T>::operator-=(const Lists<T>& other)
{
    remove(other);
    return *this;
}

template <class T>
Lists<T>& Lists<T>::operator-=(const T& item)
{
    remove(item);
    return *this;
}

template <class T>
Lists<T>& Lists<T>::operator-=(const T* items)
{
    remove(items);
    return *this;
}

template <class T>
Lists<T>& Lists<T>::operator+(const Lists<T>& other) const
{
    Lists<T> temp = *this;
    temp += other;
    return temp;
}

template <class T>
Lists<T>& Lists<T>::operator+(const T& item) const
{
    Lists<T> temp = *this;
    temp += item;
    return temp;
}

template <class T>
Lists<T>& Lists<T>::operator+(const T* items) const
{
    Lists<T> temp = *this;
    temp += items;
    return temp;
}

template <class T>
Lists<T>& Lists<T>::operator- (const Lists<T>& other) const
{
    Lists<T> temp = *this;
    temp -= other;
    return temp;
}

template <class T>
Lists<T>& Lists<T>::operator- (const T& item) const
{
    Lists<T> temp = *this;
    temp -= item;
    return temp;
}

template <class T>
Lists<T>& Lists<T>::operator- (const T* items) const
{
    Lists<T> temp = *this;
    temp -= items;
    return temp;
}

