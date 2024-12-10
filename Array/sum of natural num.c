//write a c program find the sum of natural numbers using recursion
#include<stdio.h>
int sum(int n);
int sum(int n){
    if(n!=0)
        return n+sum(n-1);
    else
        return n;
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d",sum(n));
}
