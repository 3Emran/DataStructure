#include <stdio.h>
int main() {
    int arr[300];
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Array using loop: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
   }
