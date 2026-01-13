#include <stdio.h>
#include <stdlib.h>

int heap[100];
int size=0;

void insertMaxHeap(int val){
    int pos, par;
    size++;
    pos=size;
    heap[pos]=val;

    while(pos>1){
        par=pos/2;
        if(heap[pos]>heap[par]){
            int temp=heap[par];
            heap[par]=heap[pos];
            heap[pos]=temp;

            pos=par;
        }
        else{
            break;
        }
    }
}

void printHeap(){
    for(int i=1;i<=size;i++){
        printf("%d ",heap[i]);
    }
    printf("\n");
}

int deleteRoot(){
    if(size==0){
        return -1;
    }
    int deletedValue=heap[1];

    heap[1]=heap[size];
    size--;

    int ptr=1;
    int left,right,larger;

    while(1){
        left=ptr*2;
        right=left+1;

        if(left>size){
            break;
        }else if(right>size){
            larger=left;
        }else{
            if(heap[left]>heap[right]){
                larger=left;
            }else if(heap[right]>heap[left]){
                larger=right;
            }
        }

        if(heap[ptr]>heap[larger]){
            break;
        }else{
            int temp=heap[ptr];
            heap[ptr]=heap[larger];
            heap[larger]=temp;

            ptr=larger;
        }
    }
}

void heapSort(int arr[],int n){
    size=0;

    for(int i=0;i<n;i++){
        insertMaxHeap(arr[i]);
    }for(int i=n-1;i>=0;i--){
        arr[i]=deleteRoot();
    }
}

int deleteRootMinHeap(){
    if(size==0){
        return -1;
    }
    int deletedValue=heap[1];
    heap[1]=heap[size];
    size--;

    int ptr=1;

    while(1){
        int left,right,smaller;
        
        left=ptr*2;
        right=ptr*2+1;

        if(left>size){
            break;
        }else if(right>size){
            smaller=left;
        }else{
            if(heap[left]<heap[right]){
                smaller=left;
            }else{
                smaller=right;
            }
        }

        if(heap[ptr]<heap[smaller]){
            break;
        }else{
            int temp=heap[ptr];
            heap[ptr]=heap[smaller];
            heap[smaller]=temp;

            ptr=smaller;
        }
    }
    return deletedValue;
}

int main(){
    insertMaxHeap(10);
    printHeap(); // 10
    
    insertMaxHeap(20); 
    printHeap(); // 20, 10 (20 yukarı çıktı)
    
    insertMaxHeap(15);
    printHeap(); // 20, 10, 15
    
    insertMaxHeap(30); 
    printHeap();
}
