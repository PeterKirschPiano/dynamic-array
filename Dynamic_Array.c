#include "Dynamic_Array.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define SUCCESS 1
#define ERROR 0

#define SHRINK_FACTOR 0.25

d_array_datatype_t* dyn_array_initialize(int size)
{
    d_array_datatype_t *array = calloc(size, sizeof(d_array_datatype_t));
    if(array == NULL)
    {
        puts("Array init failed.");
        free(array);
        return NULL;
    }
    else
        return array;
}

int dyn_array_element_add(d_array_datatype_t new_element, int *n_elements, int *size, d_array_datatype_t **array)
{
    if(array == NULL)
        return ERROR;

    if(*n_elements == *size)
    {
        d_array_datatype_t *temp = dyn_array_enlarge(size, *array);
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

d_array_datatype_t *dyn_array_enlarge(int *size, d_array_datatype_t *array)
{
    int old_size = *size;
    int new_size = old_size * 2;

    d_array_datatype_t *temp = calloc(new_size, sizeof(d_array_datatype_t));
    if(temp == NULL)
    {
        puts("Array enlarge failed.");
        return NULL;
    }

    if (array == NULL)
        return NULL;

    memcpy(temp, array, old_size * sizeof(d_array_datatype_t));
    free(array);
    *size = new_size;

    return temp;
}

d_array_datatype_t *dyn_array_shrink(double factor, int *size, d_array_datatype_t *array)
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
        puts("SIZE TOO SMALL.");
        return NULL;
    }

    int new_size = ceil((double)(*size) * factor);
    if(new_size < 1)
        new_size = 1;

    d_array_datatype_t *temp = calloc(new_size, sizeof(d_array_datatype_t));

    if(temp == NULL)
        return NULL;

    memcpy(temp, array, new_size * sizeof(d_array_datatype_t));

    free(array);
    *size = new_size;

    return temp;
}

void dyn_array_element_print(int n_elements, d_array_datatype_t* array)
{
    if(n_elements > 0)
    {
        for(int i = 0; i < n_elements; i++)
        {
            if(DATATYPE_CHAR)
                printf("[%d]  %c\n", i, array[i]);
            else if(DATATYPE_INT)
                printf("[%d]  %d\n", i, array[i]);
            else if(DATATYPE_DOUBLE)
                printf("[%d]  %lf\n", i, array[i]);
            else if(DATATYPE_FLOAT)
                printf("[%d]  %f\n", i, array[i]);
        }

        puts("");
    }
    else
        puts("Array is empty.");
}

int dyn_array_element_delete(d_array_datatype_t element, int *n_elements, int *size, d_array_datatype_t **array)
{
    if(*array == NULL)
        return ERROR;

    int temp = dyn_array_element_find_index(element, *n_elements, *array);

    if(temp != -1)
    {
        if(temp + 1 == *n_elements)
            (*n_elements)--;
        else
        {
            int number_of_successive_elements = *n_elements - (temp + 1);
            memcpy(&((*array)[temp]), &((*array)[temp + 1]), number_of_successive_elements * sizeof(d_array_datatype_t));
            (*n_elements)--;
        }

        double factor = SHRINK_FACTOR;
        if((double)*n_elements / (double)*size <= factor)
            *array = dyn_array_shrink(factor, size, *array);

        return SUCCESS;
    }
    else
        puts("Element not Found.");
    return ERROR;
}

d_array_datatype_t *dyn_array_element_find_address(d_array_datatype_t element, int n_elements, d_array_datatype_t *array)
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

int dyn_array_element_find_index(d_array_datatype_t element, int n_elements, d_array_datatype_t *array)
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

d_array_datatype_t *dyn_array_element_dequeue(d_array_datatype_t **array, int *size, int* n_elements)
{
    if(array == NULL || *array == NULL || n_elements == NULL || size == NULL)
        return NULL;

    if(*n_elements == 0)
    {
        puts("Queue empty.");
        return NULL;
    }

    static d_array_datatype_t temp;
    temp = **array;
    (*n_elements)--;

    if(*n_elements > 0)
        memmove(*array, *array + 1, (*n_elements) * sizeof(d_array_datatype_t));

    double factor = SHRINK_FACTOR;
    if((double)*n_elements / (double)*size <= factor)
        *array = dyn_array_shrink(factor, size, *array);

    return &temp;
}

d_array_datatype_t *dyn_array_element_pop(d_array_datatype_t **array, int *size, int *n_elements)
{
    if(array == NULL || *array == NULL || n_elements == NULL || size == NULL)
        return NULL;

    if(*n_elements == 0)
    {
        puts("Stack empty.");
        return NULL;
    }

    static d_array_datatype_t temp;
    temp = (*array)[*n_elements - 1];
    (*n_elements)--;

    double factor = SHRINK_FACTOR;
    if((double)*n_elements / (double)*size <= factor)
        *array = dyn_array_shrink(factor, size, *array);

    return &temp;
}
