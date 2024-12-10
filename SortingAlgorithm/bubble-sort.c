//bubble sort
#include<stdio.h> //2nd element smaller 1st element large swap
int main(){       //  0  1 2
    int arr[100];
    int i,j,n,t;
    printf("Enter the elements:");
    scanf("%d",&n);
    printf("Enter the integers:");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
        }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){

    if(arr[j+1] < arr[j])
       {                                     // 4 1 6  1 4 6                  arr[j]=4 && arr[j+1]=5
       t=arr[j];
       arr[j]=arr[j+1];
       arr[j+1]=t;

       }
    }

       printf("Sorted:\n");
       for(i=0;i<n;i++){
        printf("%d\n", arr[i]);

 }  } }
