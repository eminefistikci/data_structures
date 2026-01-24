#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

/*
struct Node{
    int data;
    struct Node* next;
};

struct Node* front=NULL;
struct Node* rear=NULL;

int isEmpty(){
    if(front==NULL && rear==NULL){
        return 1;
    }else{
        return 0;
    }
}

void enqueue(int value){//sona ekler
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;

    if(front==NULL){
        front=rear=newNode;
    }else{
        rear->next=newNode;
        rear=newNode;
    }
}

void dequeue(){//baştan eleman siler
    if(front==NULL && front>rear){
        printf("underlow\n");
        return;
   
    struct Node* temp=front;
    front=front->next;
    if(front==NULL){
        rear=NULL;
    }
    free(temp);
    
}}

void peek(){
    if(front==NULL){
        printf("empty\n");
        return;
    }
    printf("%d",front->data);
}

void display(){
    if(front==NULL){
        printf("empty\n");
        return;
    }
    struct Node* temp=front;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}




//ARRAY ILE QUEUE:

#define MAX 100

int queue[MAX];
int rear=-1,front=-1;

void insert(int num){
    if(rear>=MAX-1){
        printf("overflow\n");
        return;
    }else if(rear==-1 && front==-1){
        front=0;
        queue[++rear]=num;
    }else{
        queue[++rear]=num;
    }
    
}

int delete(){
    if(front==-1 || front>rear){
        printf("underflow");
    }else{
        int val=queue[front++];
        if(front>rear){
            front=rear=-1;
        }
        return val;
    }
}

int peek(){
    if(front==-1 || front>rear){
        printf("undeflow\n");
    }else{
        int val=queue[front];
        return val;
    }
}

void display(){
    for(int i=front;i<=rear;i++){
        printf("%d ",queue[i]);
    }

}

*/

struct stack{
    int data;
    struct stack* next;
};

struct stack* top=NULL;

struct stack* push(struct stack* top,int value){
    struct stack* newNode=(struct stack*)malloc(sizeof(struct stack));
    newNode->data=value;
    newNode->next=NULL;

    if(top==NULL){
        top=newNode;
        return top;
    }else{
        newNode->next=top;
        top=newNode;
        return top;
    }
}




struct node{
    int data;
    struct node* next;
    struct node* last;
};

int main(){
    int n;
    printf("enter n:");
    scanf("%d",&n);

    struct node* head=NULL;
    struct node* lastNode;

    for(int i=1;i<=n;i++){
        struct node* newNode=(struct node*)malloc(sizeof(struct node));
        newNode->data=i;
        newNode->next=NULL;
        newNode->last=NULL;

        if(head==NULL){
            head=newNode;
            lastNode=newNode;
        }else{
            lastNode->next=newNode;
            lastNode=newNode;
        }
    }

    struct node* temp=head;
    for(int i=1;i<n;i++){
        temp->last=lastNode;
        temp=temp->next;
    }
}

struct node{
    int data;
    struct node* next;
    struct node* first;
}

int main(){
    struct node* head=NULL;
    struct node* lastNode;

    int n;
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        struct node* newNode=(struct node*)malloc(sizeof(struct node));
        newNode->data=i;
        newNode->next=NULL;
        newNode->first=NULL;

        if(head==NULL){
            head=newNode;
            lastNode=newNode;
            lastNode->next=head;
        }else{
            lastNode->next=newNode;
            lastNode=newNode;
            lastNode->first=head;
        }
    }lastNode->next=head;
}