#include<stdio.h>
#include<complex.h>
double complex topdown(double complex a,int x){
    if (x==0){
        return 1;
    }
    if (x==1){
        return a;
    }
    int half=x/2;
    double complex halfresult=topdown(a,half);
    double complex result = halfresult * halfresult;
    if (x%2==1){
        result=result*a;
    }
    return result;
}
int main(){
    double complex i=I;
    int n;
    printf("Enter n : ");
    scanf("%d",&n);
    double complex result= topdown(1+i,n);
    printf("Result: %.2f + %.2fi\n", creal(result), cimag(result));
    return 0;
}