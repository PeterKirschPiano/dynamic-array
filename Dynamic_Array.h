#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#define DATATYPE_CHAR 1
#define DATATYPE_INT 0
#define DATATYPE_DOUBLE 0
#define DATATYPE_FLOAT 0

typedef char d_array_datatype_t;

typedef struct
{
    //potential size of elements
    int size;
    //tracker for the number of elements
    int n_elements;
    //pointer to the memory of the array
    d_array_datatype_t* array;
} dynamic_array_t;

// Success = 1
// Error = 0
// Error pointer = NULL

// *****Memory Management*****
// allocates memory for size * elements
d_array_datatype_t *dyn_array_initialize(int size);
// expands the array if it is full
d_array_datatype_t *dyn_array_enlarge(int *size, d_array_datatype_t *array);
// shrinks the size of the array by factor -> returns address to new array -> higher function = if n_elements / size = factor
d_array_datatype_t *dyn_array_shrink(double factor, int *size, d_array_datatype_t *array);

// *****Elements*****
// adds element to the rear of the array, returns Error or Success -> use for add to queue and add to stack
int dyn_array_element_add(d_array_datatype_t new_element, int *n_elements, int *size, d_array_datatype_t **array);
// deletes element, copies successive elements to prevent fragmentation -> returns Error or Success
int dyn_array_element_delete(d_array_datatype_t element, int *n_elements, int *size, d_array_datatype_t **array);
// prints the whole array
void dyn_array_element_print(int n_elements, d_array_datatype_t* array);
// returns the memory address of an element
d_array_datatype_t *dyn_array_element_find_address(d_array_datatype_t element, int n_elements, d_array_datatype_t *array);
// returns the index of an element
int dyn_array_element_find_index(d_array_datatype_t element, int n_elements, d_array_datatype_t *array);

// *****Queue*****
// remove the first item from the queue, return the address to the value of that item
d_array_datatype_t *dyn_array_element_dequeue(d_array_datatype_t **array, int *size, int* n_elements);

// *****STACK*****
// remove the last item from the stack, return the address to the value of that item
d_array_datatype_t *dyn_array_element_pop(d_array_datatype_t **array, int *size, int *n_elements);

#endif
