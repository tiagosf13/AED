#include <assert.h>
#include <stdio.h>

void printArray(int a[], size_t n){
    for (int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
}

int cumSum(int a[], int b[]){
    int c = 0;
    for (int i=0; i<12; i++){
        c += a[i];
        b[i] = c;
    }
}

int main(void){
    int a[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    puts("Array a: ");
    printArray(a, sizeof(a)/sizeof(a[0]));

    int b[12];
    cumSum(a, b);
    puts("\nArray b: ");
    printArray(b, sizeof(a)/sizeof(a[0]));
}

