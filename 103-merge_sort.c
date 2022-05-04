#include "sort.h"

/**
 * merge_sort - sorts the array using top-down merge sort algorithm. 
 * @array: pointer to the array to be sorted.
 * @size: size of the array.
*/
void merge_sort(int *array, size_t size)
{
    /* check for array existence and size > 1 */
    if (!array || size < 2)
        return;
    /* determine start/mid/end points */
    int start = 0;
    int end = size - 1;
    int mid = (start + end) / 2;
    /* begin division of array and subsquent merge */
    mergeSort(array, start, mid);
    mergeSort(array, mid + 1, end);
    merge(array, start, mid, end);
}

/**
 * mergeSort - divides the array down to single indexes and then merges up.
 * @array: pointer to the array to be merged.
 * @start: starting index.
 * @end: ending index.
 */
void mergeSort(int *array, int start, int end)
{
    /* determine if further division is necessary and then merge */
    if(start < end) {
        int mid = ((start + end - 1) / 2);
        mergeSort(array, start, mid);
        mergeSort(array, mid + 1, end);
        merge(array, start, mid, end);
    }
}

/**
 * merge - performs the merge of divided arrays.
 * @array: pointer to the array to be merged.
 * @start: starting index.
 * @mid: middle index.
 * @end: ending index.
 */
void merge(int *array, int start, int mid, int end)
{
    printf("Merging...\n");
    int array_len = end + start - 1;
    int temp_array[array_len];
    int i = start, j = mid + 1, k = 0;
    int x;
    printf("[left]: ");
    for(x = i; x < j; x++) {
        printf("%d", array[x]);
        if(x < (j - 1))
            printf(", ");
    }
    printf("\n");
    printf("[right]: ");
    for(; x < end + 1; x++) {
        printf("%d", array[x]);
        if(x < end)
            printf(", ");
    }
    printf("\n");
    while(i <= mid && j <= end) {
        if(array[i] <= array[j]) {
            temp_array[k] = array[i];
            k++;
            i++;
        }
        else {
            temp_array[k] = array[j];
            k++;
            j++;
        }
    }
    while(i <= mid) {
        temp_array[k] = array[i];
        k++;
        i++;
    }
    while(j <= end) {
        temp_array[k] = array[j];
        k++;
        j++;
    }
    printf("[Done]: ");
    for (i = start; i <= end; i++) {
        array[i] = temp_array[i - start];
        printf("%d", array[i]);
        if (i != end)
            printf(", ");
        else
            printf("\n");
    }
}
