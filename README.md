# Dynamic Integer Array Library  

A simple **dynamic integer array** implementation in C, supporting **automatic resizing, queue operations, and stack operations**.  

## Features  
✅ Dynamic memory allocation for int, char, float and double arrays  
✅ Automatic resizing (expansion & shrinking)  
✅ Stack operations (`push`, `pop`)  
✅ Queue operations (`enqueue`, `dequeue`)  
✅ Element management (add, delete, search)  
✅ Helper functions for printing & memory management  

---

## Usage  

### Memory Management  
- `int_array_initialize(int size)`: Initializes an array with a given size.  
- `int_array_enlarge(int *size, int *array)`: Expands the array when full.  
- `int_array_shrink(double factor, int *size, int *array)`: Shrinks the array when too many elements are removed.  

### Element Operations  
- `int_array_element_add(int new_element, int *n_elements, int *size, int **array)`: Adds an element to the array.  
- `int_array_element_delete(int element, int *n_elements, int *size, int **array)`: Deletes an element and shifts the remaining elements.  
- `int_array_element_print(int n_elements, int* array)`: Prints the array contents.  
- `int_array_element_find_adress(int element, int n_elements, int *array)`: Finds and returns the memory address of an element.  
- `int_array_element_find_index(int element, int n_elements, int *array)`: Finds the index of an element.  

### Queue Operations  
- `int_array_element_dequeue(int **array, int *size, int *n_elements)`: Removes the first element from the queue and returns its address.  

### Stack Operations  
- `int_array_element_pop(int **array, int *size, int *n_element)`: Removes the last element from the stack and returns its address.  

---

## Compilation & Example Usage  

### Compilation  
To compile a C program using this library, use `gcc`:  
```sh
gcc -o program main.c dynamic_array.c
