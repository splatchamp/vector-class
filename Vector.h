#ifndef VECTOR_H
#define VECTOR_H
#include <string>
#include <iostream>
#include <stdexcept>
#include <sstream>
using std::cout, std::endl, std::cerr, std::cin, std::string, std::to_string;

const size_t INITIAL_CAPACITY = 10;
const std::string OUT_OF_RANGE_MESSAGE = "Index provided is out of range";

template <class T>
class Vector{
private:
    int capacity;
    int vec_size;
    T* data = nullptr;
public:
    Vector(size_t size = INITIAL_CAPACITY) {
        capacity = size;
        vec_size = 0;
        data = new T[capacity];
    }

    ~Vector() {
        delete[] data;
        data = nullptr;
    }


    const T& operator[] (size_t index) const {
        return data[index];
    }


    T& operator[] (size_t index) {
        return data[index];
    }


    const T& at(size_t index) const {
        if (index < vec_size)
            return data[index];
        else
            throw std::out_of_range(OUT_OF_RANGE_MESSAGE);
    }


    T& at(size_t index) {
        if (index < vec_size)
            return data[index];
        else
            throw std::out_of_range(OUT_OF_RANGE_MESSAGE);
    }


    bool empty() const {
        if (data)
            return false;
        else
            return true;
    }


    size_t size() const {
        return vec_size;
    }


    void resize(size_t new_size) {
        T* new_array = new T[new_size];
        if (vec_size < new_size) {
            for (int i = 0; i < vec_size; i++)
                new_array[i] = data[i];
        }
        else {
            for (int i = 0; i < new_size; i++) {
                new_array[i] = data[i];
            }
        }
        delete[] data;
        data = new_array;
        capacity = new_size;
    }


    string toString() const {
        string result = "";
        for (int i = 0; i < vec_size; i++) {
            if (i == vec_size - 1)
                result += to_string(data[i]);
            else
                result = result + to_string(data[i]) + ' ';
        }
        return result;
    }


    void push_back(const T& val) {
        if (vec_size == capacity) {
            resize(capacity * 2);
        }
        if (vec_size == 0)
            data[0] = val;
        else {
            T *temp = new T[capacity];
            for (int i = 0; i < vec_size; i++) {
                temp[i] = data[i];
            }
            temp[vec_size] = val;
            delete[] data;
            data = temp;
        }
        vec_size++;
    }


    void insert(size_t index, const T& value) {
        if (index > vec_size)
            throw std::out_of_range(OUT_OF_RANGE_MESSAGE);
        if (vec_size == capacity)
            resize(capacity * 2);
        for (int i = vec_size; i > index; i--) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        vec_size++;
    }


    void pop_back() {
        data[vec_size - 1] = NULL;
        vec_size--;
    }


    void erase(size_t index) {
        if (index >= vec_size)
            throw std::out_of_range(OUT_OF_RANGE_MESSAGE);

        for (int i = index; i < vec_size; i++) {
            data[i] = data[i + 1];
        }
        vec_size--;
    }


    void swap(Vector<T>& other) {
        size_t temp = capacity;
        capacity = other.capacity;
        other.capacity = temp;

        temp = vec_size;
        vec_size = other.vec_size;
        other.vec_size = temp;

        T* temp_vect = data;
        data = other.data;
        other.data = temp_vect;
    }


    Vector<T>& operator= (const Vector<T>& other) {
        if (other)
            delete[] other;
        int new_vec_size = other.vec_size;
        int new_capacity = other.capacity;
        T* new_data = new int[other.capacity];
        for (int i = 0; i < vec_size; i++) {
            new_data[i] = other.data[i];
        }
        data = new_data;
        vec_size = new_vec_size;
        capacity = new_capacity;
        return this;
    }


    bool operator== (const Vector<T>& other) {
        if (vec_size != other.vec_size)
            return false;
        for (int i = 0; i < vec_size; i++)
            if (data[i] != other.data[i])
                return false;
        return true;
    }
};

#endif //VECTOR_H