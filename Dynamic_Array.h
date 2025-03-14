#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

typedef struct
{
    //potential size of elements
    int size;
    //tracker for the number of elements
    int n_elments;
    //pointer to the memory of the array
    int* array;
}dynamic_int_array_t;

//Success = 1
//Error = 0
//Error pointer = NULL

//*****Memory Managment*****
//allocates memory for size * elements
int *int_array_initialize(int size);
//expands the array if it is full
int *int_array_enlarge(int *size, int *array);
//shrinks the size of the array by factor -> returns adress to new array -> higher function = if n_elements / size = factor
int *int_array_shrink(double factor, int *size, int *array);

//*****Elements*****
//adds element to the rear of the array, returns Error or Success -> use for add to queue and add to stack
int int_array_element_add(int new_element, int *n_elements, int *size, int **array);
//deletes element, copys successive elements to prevent fragmantation -> returns Error or Success
int int_array_element_delete(int element, int *n_elements, int *size, int **array);
//prints the whole array
void int_array_element_print(int n_elements, int* array);
//returns the memory adress of an element
int *int_array_element_find_adress(int element, int n_elements, int *array);
//returns the index of an element
int int_array_element_find_index(int element, int n_elements, int *array);

//*****Queue*****
//remove the first item from the queue, return the adress to the value of that item
int *int_array_element_dequeue(int **array, int *size, int* n_elements);

//*****STACK*****
//remove the last item from the stack, return the adress to the value of that item
int *int_array_element_pop(int **array, int *size, int *n_element);

#endif
