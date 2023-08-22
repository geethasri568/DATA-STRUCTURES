#include <stdio.h>

void mergeArrays(int arr1[], int size1, int arr2[], int size2, int result[]) {
    int i, j, k;

    for (i = 0; i < size1; i++) {
        result[i] = arr1[i];
    }
    
  
    for (j = 0, k = size1; j < size2; j++, k++) {
        result[k] = arr2[j];
    }
}

int main() {
	int i;
    int arr1[] = {1, 2, 3};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    
    int arr2[] = {4, 5, 6};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    int mergedSize = size1 + size2;
    int mergedArray[mergedSize];
    
    mergeArrays(arr1, size1, arr2, size2, mergedArray);
    
    printf("\nMerged Array: ");
    for (i = 0; i < mergedSize; i++) {
        printf("%d ", mergedArray[i]);
    }
    
    return 0;
}
