#include<iostream> 
#include<stdlib.h>
using namespace std;

struct Array{
    int A[20];
    int size;
    int len;
};

void Append(struct Array *arr, int x){
    if(arr->len < arr->size){
        arr->A[arr->len++] = x;
    }
}

void Display(struct Array arr){
    cout<<"Elements are: "<<endl;
    for(int i = 0; i<arr.len; i++){
        cout<<arr.A[i]<<" ";
    }
    cout<<endl;
}

void Insert(struct Array *arr, int index, int x){
    if(index>=0 && index<=arr->len){
        for(int i = arr->len; i>index; i--){
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = x;
        arr->len++;
    }
}

int Delete(struct Array *arr, int index){
    int x=0;
    if(index>=0 && index<arr->len){
        x = arr->A[index];
        for(int i = index; i<arr->len-1; i++){
            arr->A[i] = arr->A[i+1];
        }
        arr->len--; 
        return x;
    }
    return 0;
}

void swap(int *x, int *y){
    int t;
    t = *x;
    *x = *y;
    *y = t;
}

// int LinearSearch(struct Array *arr, int key){
//     for(int i = 0 ; i<arr->len; i++){
//         if(key == arr->A[i]){
//             swap(&arr->A[i], &arr->A[0]);
//             return i;
//         }
//     }
//     return -1;
// }

int BinSearch(struct Array arr, int key){
    int l, mid, h;
    l = 0;
    h = arr.len-1;
    while(l<=h){
        mid = (l+h)/2;
        if(key == arr.A[mid]){
            return mid;
        }
        else if(key < arr.A[mid]){
            h = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return -1;
}

int Rbinsearch(int a[],int l, int h, int key){
    int mid;
    if(l<=h){
        mid = (l+h)/2;
        if(key == a[mid])
            return mid;
        else if(key<a[mid]){
            return Rbinsearch(a,l,mid-1,key);
        }
        else{
            return Rbinsearch(a,mid+1, h, key);
        }
    }

    return -1;
}


int Get(struct Array arr, int index){
    if(index>=0 && index < arr.len){
        return arr.A[index];
    }
    return -1;
}

void Set(struct Array *arr, int index, int x){
    if(index>=0 && index<arr->len){
        arr->A[index] = x;
    }
}

int Max(struct Array arr){
    int max = arr.A[0];
    for(int i = 1; i<arr.len; i++){
        if(arr.A[i] > max){
            max = arr.A[i];
        }
    } 
    return max;
}

int Min(struct Array arr){
    int min = arr.A[0];
    for(int i = 1; i<arr.len; i++){
        if(arr.A[i] < min){
            min = arr.A[i];
        }
    } 
    return min;
}

int Sum(struct Array arr){
    int s = 0;
    for(int i = 0; i<arr.len; i++){
        s += arr.A[i];
    }
    return s;
}

float avg(struct Array arr){
    
    return (float)Sum(arr) / arr.len;

}

void Reverse(struct Array *arr){
    int *B;
    int i, j;

    B = (int *)malloc(arr->len * sizeof(int));

    for(int i = arr->len - 1, j = 0; i>=0; i--,j++){
        B[j] = arr->A[i];
    }

    for(int i = 0; i<arr->len; i++){
        arr->A[i] = B[i];
    }
}

void AReverse(struct Array *arr){
    int i, j;
    for(i = 0, j = arr->len-1; i<j; i++, j--){
        swap(arr->A[i], arr->A[j]);
    }
}

void InserSort(struct Array *arr, int x){
    if(arr->len ==  arr->size) return;
    int i = arr->len - 1;
    while(i>=0 && x < arr->A[i]){
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
    arr->len++;
}

int isSorted(struct Array arr){
    for(int i = 0; i<arr.len-1; i++){
        if(arr.A[i] > arr.A[i+1]){
            return 0;
        }
    }
    return 1;
}

void Neg_On_Left(struct Array *arr){
    int i = 0; int j = arr->len-1;
    while(i<j){
        while(arr->A[i] < 0){i++;}
        while(arr->A[j] >= 0){j--;}
        if(i<j)
            swap(arr->A[i],arr->A[j]);
    }
}

struct Array* Merge(struct Array *arr1, struct Array *arr2){
    int i=0, j=0, k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->len && j<arr2->len){
        if(arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }
    for(;i<arr1->len; i++)
        arr3->A[k++] = arr1->A[i];
    for(;j<arr2->len; j++)
        arr3->A[k++] = arr2->A[j];
    arr3->len = arr1->len + arr2->len;
    arr3->size = 10;
    
    return arr3;
}


int main(){
    

    struct Array arr1 = {{2,6,10,15,25},10,5};
    struct Array arr2 = {{3,4,7,18,20},10,5};
    struct Array *arr3;

    arr3 = Merge(&arr1, &arr2);
    Display(*arr3);

    // Append(&arr, 10);
    // printf("\nDeleted val: %d\n\n",Delete(&arr, 4));

    // printf("%d\n", LinearSearch(&arr, 6));
    // printf("%d\n",BinSearch(arr,2));
    // AReverse(&arr);

    // InserSort(&arr, 67);

    // printf("%d \n", isSorted(arr));
    // Neg_On_Left(&arr);
    // Display(arr);

    return 0;
}