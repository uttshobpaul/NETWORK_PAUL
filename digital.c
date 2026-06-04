#include<stdio.h>
int main(){
    int i;
    printf("digital signal (square sigal)\n");
    for(i=0 ; i<20; i++){
        if(i%2==0){
            printf("time %d : 1\n",i);
        }else{
            printf("time %d : 0\n",i);
        }
    }

    return 0;
}