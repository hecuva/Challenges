#include <stdio.h>
#include <stdlib.h>

/************************************************************************************************
Two-Sum Indices Variants

Write a C program to get the indices of two numbers in a given array of integers. This will 
enable you to get the sum of two numbers equal to a specific target.

Expected Output:

Original Array: 4  2  1  5  
Target Value: 7
Indices of the two numbers whose sum equal to target value: 7
1 3
***********************************************************************************************/

int* twoSumIndicesVariants(int* arr, int size, int target){
    int sum = 0;

    // Setting up dynamic memory
    int* results = (int*)malloc(sizeof(int) * size);

    if (arr == NULL) {

        return NULL; 
    }
    // Double for-loop checks two indices sums for the target value. complexity- n^2 worst case
    for(int i = 0; i < size; i++){
        for(int j = 0; j< size; j++){

            if(i == j) j++; // if its the same index move on

            sum = arr[i] + arr[j];

            if (sum == target){
                results[0] = i;
                results[1]=j;
                return results;
            }
        }
    }
}

int main(){
    // Given from problem
    int givenArray[4] = {4, 2, 1, 5};
    int size = 4;
    int target = 7;

    // Initailizing dynamic memory
    int* array1 = (int*)malloc(sizeof(int) * size);
    if (array1 == NULL) {

        return 0; 
    }

    // Swapping the given array to a pointer
    for(int i = 0; i < size;i++){array1[i] = givenArray[i];}
    
    // Runs the two sum indices function returns the two indices that sum up to the target
    int* tarArr =  twoSumIndicesVariants(array1, 4, target);
    
    // Results after running the function
    printf("Original Array: ");

    // Prints the given array
    if (array1 != NULL) {
        for (int i = 0; i < 4; i++) {
            printf("%d ", array1[i]);
        }
        printf("\n");
        free(array1); // Free the allocated memory
    }
    
    // Prints the two indices that sum up to the target
    printf("Indices of the two numbers whose sum equal to target value: %d\n %d %d\n",target,tarArr[0],tarArr[1]);

    free(tarArr);// Free the allocated memory

    return 0;
}