#include<stdio.h>
#include<math.h>
int main(){
    float t;
    printf("analog signal(sign wave)\n");
    for(t=0 ; t<=6.28 ; t+=0.2){
        printf("time =%2f  amplitute=%2f\n",t,sin(t));
    }
    return 0;
}