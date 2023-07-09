#include <stdio.h>

int f(int x) { return x * x - 1; }
int g(int x) { return x / 3; }

void mem_copy(char *src,char *dst,size_t size)
{
for(size_t i = 0;i < size;i++)
dst[i] = src[i];
}

int main(void)
{   
    int c = 0;
    int r = -20220204;
    for(int i = 0;i <= 3;i++){
        for(int j = 2 * i;j <= 2 * 3;j++){
            r += j / (i + 1);
            c++;
        }
    }
    
    printf("%d",c);
}