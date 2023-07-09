#include <stdio.h>
#include <stdlib.h>

int* read(size_t* size){

    size_t n;

    printf("Número de elementos do array:\n");
    scanf("%u", &n);
    
    int* array = malloc(n*sizeof(int)); // alocar memória para o array
    if (array == NULL){
        *size = 0;
        return NULL;
    }

    for(size_t i = 0; i < n; i++){
        printf("A[%u] = ", i);
        scanf("%d", &array[i]);
    }

    *size = n;

    return array;
}

void display(int *a, size_t size){
    printf("Array = [");
    for(int i = 0; i < size-1; i++){
        printf("%d,", a[i]);
    }
    printf("%d]\n", a[size-1]);
}

int* append(int* array1, size_t size1, int* array2, size_t size2){
    
    int* array_total = malloc((size1+size2)*sizeof(int));
    if (array_total == NULL){
        return NULL;
    }

    for(int i = 0; i < size1; i++){
        array_total[i] = array1[i];
    }

    for(int i = 0; i < size2; i++){
        array_total[i+size1] = array2[i];
    }

    return array_total;
}

int main(void){
    int *novo_array;
    int *novo_array2;
    size_t size;
    int a[] = {1, 2, 3, 4, 5};

    display(a, sizeof(a)/sizeof(a[0]));

    novo_array = read(&size);
    display(novo_array, size);

    novo_array2 = append(a, sizeof(a)/sizeof(a[0]), novo_array, size);
    display(novo_array2, size+(sizeof(a)/sizeof(a[0])));

    // libertar memória alocada
    free(novo_array);
    free(novo_array2);
    return 0;
}

