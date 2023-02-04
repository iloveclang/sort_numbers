#include <stdio.h>
#include <stdlib.h>

#define TYPE    int
#define SIZE    5

TYPE get_resistor_data(void) {  // dunno how, so just generate random number
    return (TYPE) (rand() % 100);
}


void sort_descending(TYPE *arr, int size) {
    int i, j;
    TYPE temp;

    if (size > 1) {
        size--; // adjust size to max index
    }
    else {
        printf("Can't sort less than 2 numbers!");
        return;
    }
    
    for (i = size; i > 0; i--) {
        for (j = (i - 1); j >= 0 ; j--) {
            if (arr[i] > arr[j]) {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
            else {
                break;
            }
        }
    }
}

int main() {
    int i;
    TYPE array[SIZE] = {0};  // intialize full array for sort safety
    
    for (i = 0; i < SIZE; i++) {   // fill array with data
        array[i] = get_resistor_data();
        printf("array[%d] = %d\n", i, array[i]);
    }
    
    sort_descending(array, SIZE);

    puts("\nSorted data:\n");
    for (i = 0; i < SIZE; i++) {   // print sorted data
        printf("array[%d] = %d\n", i, array[i]);
    }

    return 0;
}
