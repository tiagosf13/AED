#include <stdio.h>
#include <stdlib.h>

void displayPol(double* coef, unsigned int degree){
    printf("Polinómio: ");
    for (int i = degree; i <= degree; i--){
        if (i == 0){
            printf("%g", coef[i]);
        }
        else if (i == 1){
            printf("%gx", coef[i]);
        }
        else{
            printf("%gx^%d", coef[i], i);
        }
        if (i != 0){
            printf(" + ");
        }
    }
    printf("\n");
}

double* read(size_t* grau){

    size_t n;

    printf("Grau do polinómio:\n");
    scanf("%llu", &n);
    
    double* array = malloc((n+1)*sizeof(double)); // alocar memória para o array
    if (array == NULL){
        *grau = 0;
        return NULL;
    }

    for(int i = n; i >= 0; i--){
        printf("Coeficiente grau %llu = ", i);
        scanf("%lf", &array[i]);
    }

    *grau = n;

    return array;
}

int main(void){
    double *coef;
    size_t size;

    coef = read(&size);

    displayPol(coef, size);

    free(coef);
    return 0;
}