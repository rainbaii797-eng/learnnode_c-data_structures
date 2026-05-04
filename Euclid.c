//欧几里得算法的核心思想是：两个整数的最大公约数等于其中较小的数和两数相除余数的最大公约数。用数学公式表示为：
//gcd(a,b)=gcd(b,a mod b),当余数为0时，此时的除数就是最大公约数。

#include <stdio.h>
int ReturnMax(int a,int b){
    if(a > b){
        return a;
    }else{
        return b;
    }
}

int ReturnMin(int a,int b){
    if(a < b){
        return a;
    }else{
        return b;
    }
}

//计算最大公约数,大的在前，小的在后
int EuclidGcd(int a,int b){
    int r;
    r = a % b;
    while(r != 0){
        r = a % b;
        a = b;
        b = r; 
    }
    return a;
}

int main(){
    int a,b;
    printf("please erter two integers:\n");
    scanf("%d %d",&a,&b);
    int max = ReturnMax(a,b);
    int min = ReturnMin(a,b);
    int gcd = EuclidGcd(max,min);
    printf("The greastest common divisor of %d and %d is %d\n",a,b,gcd);
    return 0;
}