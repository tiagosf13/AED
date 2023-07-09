#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>

void do_it(int N){

    int i;
    double angulo_radianos, seno_graus, cosseno_graus;

    printf("%2s %12s %15s %15s\n", "ang", "sen(ang)", "cos(ang)", "sen^2+cos^2");
    printf("%2s %12s %15s %15s\n", "---", "----------", "-------------", "-----------");
    for (i = 0; i <= N; i+=5) {
        angulo_radianos = (i*M_PI)/180;
        printf("%3d %12f %15.10f %15f\n", i, sin(angulo_radianos), cos(angulo_radianos), sin(angulo_radianos)*sin(angulo_radianos)+cos(angulo_radianos)*cos(angulo_radianos));
    }
}

void main(){
    
    do_it(90);
}