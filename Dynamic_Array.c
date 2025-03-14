#include "Dynamic_Array.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define SUCCESS 1
#define ERROR 0

#define SHRINK_FACTOR 0.25

int* int_array_initialize(int size)
{
    int *array = calloc(size, sizeof(int));
    if(array == NULL)
    {
        puts("array init failed.");
        free(array);
        return NULL;
    }
    else
        return array;
}

int int_array_element_add(int new_element, int *n_elements, int *size, int **array)
{
    if(array == NULL)
        return ERROR;

    if(*n_elements == *size)
    {
        int *temp = int_array_enlarge(size, *array);
        //enlarge the array
        if(temp != NULL)
        {
            *array = temp;

            (*array)[*n_elements] = new_element;
            (*n_elements)++;
            return SUCCESS;
        }
        else
            return ERROR;
    }
    else
    {
        (*array)[*n_elements] = new_element;
        (*n_elements)++;
        return SUCCESS;
    }
}

int *int_array_enlarge(int *size, int *array)
{
    int old_size = *size;
    int new_size = old_size * 2;

    //alloc new space
    int *temp = calloc(new_size, sizeof(int));
    if(temp == NULL)
    {
        puts("int array enlarge failed.");
        return NULL;
    }

    if (array == NULL)
        return NULL;

    //copy old data to new array
    memcpy(temp, array, old_size * sizeof(int));
    //free old memory
    free(array);
    //update size
    *size = new_size;

    return temp;
}

int *int_array_shrink(double factor, int *size, int *array)
{
    if(array == NULL)
        return NULL;

    if(factor >= 1)
    {
        puts("FACTOR >= 1!");
        return NULL;
    }

    if(*size <= 1)
    {
        puts("SIZE TO SMALL.");
        return NULL;
    }

    //if we ever want an array with an uneven size -> this rounds the new size up
    int new_size = ceil((double)(*size) * factor);

    if(new_size < 1)
        new_size = 1;

    int *temp = calloc(new_size, sizeof(int));

    if(temp == NULL)
        return ERROR;
    //cpy memory value
    memcpy(temp, array, new_size * sizeof(int));

    free(array);
    //updated size
    *size = new_size;

    return temp;
}

void int_array_element_print(int n_elements, int* array)
{
    if(n_elements > 0)
    {
        for(int i = 0; i < n_elements; i++)
            printf("[%d] %d\n", i, array[i]);
    }
    else
        puts("array is empty.");

    puts("");
}

int int_array_element_delete(int element, int *n_elements, int *size, int **array)
{
    if(*array == NULL)
        return ERROR;

    //find the index of the element in question
    int temp = int_array_element_find_index(element, *n_elements, *array);

    if(temp != -1)
    {
        //if the element is the last element in the array simply reduce number of elements
        if(temp + 1 == *n_elements)
            (*n_elements)--;
        else
        {
            int number_of_successive_elements = *n_elements - (temp + 1);
            //copy the rest of the array over the element -> regardless if its the last element
            memcpy(array[temp], array[temp + 1], number_of_successive_elements * sizeof(int));
            (*n_elements)--;
        }
        //resizing section
        double factor = SHRINK_FACTOR;
        if((double)*n_elements / (double)*size <= factor)
            *array = int_array_shrink(factor, size, *array);


        return SUCCESS;
    }
    else
        puts("Element not Found.");
    return ERROR;
}

int *int_array_element_find_adress(int element, int n_elements, int *array)
{
    if(array == NULL)
        return NULL;

    for(int i = 0; i < n_elements; i++)
    {
        if(array[i] == element)
            return &array[i];
    }

    return NULL;
}

int int_array_element_find_index(int element, int n_elements, int *array)
{
    if(array == NULL)
        return -1;

    for(int i = 0; i < n_elements; i++)
    {
        if(array[i] == element)
            return i;
    }

    return -1;
}

int *int_array_element_dequeue(int **array, int *size, int* n_elements)
{
    if(array == NULL || *array == NULL || n_elements == NULL || size == NULL)
        return NULL;

    if(*n_elements == 0)
    {
        puts("Queue empty.");
        return NULL;
    }

    //static buffer variable
    static int temp = 0;
    //save value of element to pop
    temp = **array;
    (*n_elements)--;

    //copy remaining elements
    if(*n_elements > 0)
        memcpy(*array, *array + 1, (*n_elements) * sizeof(int));

    //resizing section
    double factor = SHRINK_FACTOR;
    if((double)*n_elements / (double)*size <= factor)
        *array = int_array_shrink(factor, size, *array);

    //return memory adress of static buffer
    return &temp;
}

int *int_array_element_pop(int **array, int *size, int *n_elements)
{
    if(array == NULL || *array == NULL || n_elements == NULL || size == NULL)
        return NULL;

    if(*n_elements == 0)
    {
        puts("Stack empty.");
        return NULL;
    }

    //static buffer variable
    static int temp = 0;
    //save value of element to pop
    temp = (*array)[*n_elements - 1];
    (*n_elements)--;

    //resizing section
    double factor = SHRINK_FACTOR;
    if((double)*n_elements / (double)*size <= factor)
        *array = int_array_shrink(factor, size, *array);

    //return memory adress of static buffer
    return &temp;
}
