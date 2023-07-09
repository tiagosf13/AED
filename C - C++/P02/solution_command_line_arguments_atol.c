#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int IsInteger(char *token){
    int to_go = 0;
    for (size_t i = 0  ; i < strlen(token); i++){
        if (token[i] < '0' || token[i] > '9')
            to_go = 0;
        else
            to_go = 1;
    }
    return to_go;
}


int main(int argc,char *argv[argc])
{
    for(size_t i = 1;i < argc;i++){
        char *token = argv[i];
        if (IsInteger(token)){
            printf("argv[%lld] = \"%s\" integer value: %ld\n",i,token,atol(token));
        }
        else{
            printf("argv[%lld] = \"%s\"\n",i,token);
        }
    }
    return 0;
}

