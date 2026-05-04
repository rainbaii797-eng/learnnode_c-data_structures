#include <stdio.h>
int fibonaci(int n){
    if(n>0&&n<=2)
        return 1;
    else if(n<=0)
        printf("input error\n");
    else
    return fibonaci(n-1)+fibonaci(n-2);
}

int main(){
    int n;
    for(n=1;n<=100;n++){
        printf("%d ",fibonaci(n));
    }
    return 0;
}