#include <cstdlib>
#include <iostream>

using std::size_t;

template <class elem> 
class MyDynamicArray {
private:
    size_t size;        // size of array in array
    size_t capacity;    // maximum current capacity
    elem* array;           // pointer to actual items in memory
    
    const static int initial_size = 32;
    const static int size_multiply = 2;

    void resize();
public:
    MyDynamicArray();
    ~MyDynamicArray();

    std::size_t get_size();
    void push_back(elem &item);
    elem& operator[] (size_t index);
};

template <class elem> 
MyDynamicArray<elem>::MyDynamicArray() {
    size = 0;
    capacity = initial_size;

    array = new elem[capacity];
}

template <class elem> 
MyDynamicArray<elem>::~MyDynamicArray() {
    if (array) {
        delete[] array;
    }
}

template <class elem>
void MyDynamicArray<elem>::resize(){
    capacity *= size_multiply;
    elem *new_array = new elem[capacity];

    for (size_t i=0;i<size;i++){
        new_array[i] = array[i];
    }

    delete[] array;
    array = new_array;
}

template <class elem>
void MyDynamicArray<elem>::push_back(elem &item){
// TODO: allow resize of dynamic array    
    if (size >= capacity) {
        resize();
    };

    array[size] = item;
    ++size;
}

template <class elem>
elem& MyDynamicArray<elem>::operator[] (size_t index) {
    if (index < size - 1) {
        return array[index];
    } else {
        std::cout << "Index out of range.\n";
        // TODO: add exception throw
    }
}