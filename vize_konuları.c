#include <stdio.h>
#include <stdlib.h>

int stack[10];
int top=-1;

int main(){
    int arr[10];
    int n;

    printf("how many elements are you going to enter?\n");
    scanf("%d",&n);

    printf("enter the elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        push(arr[i]);
    }
    for(int i=0;i<n;i++){
        arr[i]=pop();
    }
}