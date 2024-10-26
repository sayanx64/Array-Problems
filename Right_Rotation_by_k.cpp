// Given an array of integers of size n and an integer d, the task is to rotate the array elements to the right by k positions.

#include<stdio.h>

int main(){
    int n;
    printf("Enter array size: "); scanf("%d", &n);
    int A[n];
    printf("Enter array elems: ");
    for(int i = 0; i<n ; i++){
        scanf("%d", &A[i]);
    }

    int k;
    printf("Enter the value of k: "); scanf("%d", &k);

    k = k%n;

    printf("Array before right rotation : "); 
    for(int i = 0; i<n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
  
    // right rotation using reversing
    for(int start = 0, end = n-k-1; start<end; start++, end--){
        int temp = A[start];
        A[start] = A[end];
        A[end] = temp;
    }

    for(int start = n-k, end = n-1; start<end; start++, end--){
        int temp = A[start];
        A[start] = A[end];
        A[end] = temp;
    }
    
    for(int start = 0, end = n-1; start<end; start++, end--){
        int temp = A[start];
        A[start] = A[end];
        A[end] = temp;
    }

    printf("Array after rotating to the right by %d positions: ",k);
    for(int i = 0; i<n; i++){
        printf("%d ",A[i]);
    }
    printf("\n");
    return 0;
}
