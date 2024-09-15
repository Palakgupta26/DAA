// Starting from F(1)=1, F(2)=2, find nth fibonacci number in O(n) time and theta(1) space.

#include <stdio.h>
int main()
{
    int n,i;
    long long a=1,b=2,c;
    printf("Enter n to find fibonacci : ");
    scanf("%d",&n);

    if(n==1){
        printf("Fibonacci num is 1");
    }
    else if(n==2){
        printf("Fibonacci num is 2");
    }
    else{
        for (i=2;i<n;i++){
            c=a+b;
            a=b;
            b=c;
        }
        printf("Fibonacci num is %lld",c);
    }
    return 0;
}