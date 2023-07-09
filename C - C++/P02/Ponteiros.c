void f1(int a, int b){
    a = 10;
    b = 100;
}

void f2(int *a, int *b){
    *a = 3; // estamos a alterar o valor da variavel a que o ponteiro *a aponta  (neste caso chamamos a função f2 com x = 0 e y = 1), ou se
    *b = 4; //  ou seja, estamos a mudar o valor da variavel x
}

void swap1(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}

void swap2(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void){
    int x = 0;
    int y = 1;
    f1(x, y); // estamos a enviar os valores de x e y para a função f1
    printf("%d %d\n", x, y); // aqui estamos a imprimir os valores da variavel x e y na função main (0 e 1) CALL-BY-VALUE

    f2(&x, &y); // estamos a enviar os ponteiros de x e y para a função f2
    printf("%d %d\n", x, y); // aqui estamos a imprimir os valores da variavel x e y na função main (1000 e 10000) CALL-BY-POINTER
                             // ou seja, mudamos os valores de x e y em f2, o que muda de f1 para f2?


    swap1(x, y);
    printf("A = %d B = %d\n", x, y);

    swap2(&x, &y);
    printf("A = %d B = %d\n", x, y);
}