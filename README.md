Dynamic Integer Array Library
A simple dynamic integer array implementation in C, supporting automatic resizing, queue operations, and stack operations.

Features
✅ Dynamic memory allocation for integer arrays
✅ Automatic resizing (expansion & shrinking)
✅ Stack operations (push, pop)
✅ Queue operations (enqueue, dequeue)
✅ Element management (add, delete, search)
✅ Helper functions for printing & memory management

Usage
Memory Management
int_array_initialize(int size): Initializes an array with a given size.
int_array_enlarge(int *size, int *array): Expands the array when full.
int_array_shrink(double factor, int *size, int *array): Shrinks the array when too many elements are removed.
Element Operations
int_array_element_add(int new_element, int *n_elements, int *size, int **array): Adds an element to the array.
int_array_element_delete(int element, int *n_elements, int *size, int **array): Deletes an element and shifts the remaining elements.
int_array_element_print(int n_elements, int* array): Prints the array contents.
int_array_element_find_adress(int element, int n_elements, int *array): Finds and returns the memory address of an element.
int_array_element_find_index(int element, int n_elements, int *array): Finds the index of an element.
Queue Operations
int_array_element_dequeue(int **array, int *size, int *n_elements): Removes the first element from the queue and returns its address.
Stack Operations
int_array_element_pop(int **array, int *size, int *n_element): Removes the last element from the stack and returns its address.
How to Use
Include the header file in your project:
c
Kopieren
Bearbeiten
#include "dynamic_array.h"
Initialize a dynamic array:
c
Kopieren
Bearbeiten
int *arr = int_array_initialize(10);
Add elements, remove elements, or perform stack/queue operations:
c
Kopieren
Bearbeiten
int_array_element_add(5, &n_elements, &size, &arr);
int *popped_value = int_array_element_pop(&arr, &size, &n_elements);
License
This project is open-source, and you are free to modify and use it as needed.

