#include<stdio.h>
int main(){

    int n;
    printf("Enter Array Size: "); scanf("%d",&n);
    int A[n];
    printf("Enter array elems: ");
    for(int i = 0; i<n; i++){
        scanf("%d",&A[i]);
    }

    printf("Before shifting: ");
    for(int i = 0; i<n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
    // shifting
    int i = 0, j = n-1;
    while(i<j){
        while(A[i] < 0){
            i++;
        }
        while(A[j] >= 0){
            j--;
        }
        if(i<j){
            // swap
            int t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    }

    printf("After shifting: ");
    for(int i = 0; i<n; i++){
        printf("%d ", A[i]);
    }
    return 0;
}