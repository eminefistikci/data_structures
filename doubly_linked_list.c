#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node* createNode(int value){
    Node* n=(Node*)malloc(sizeof(Node));
    n->data=value;
    n->next=NULL;
    n->prev=NULL;
    return n;
}

Node* insertBeg(Node* head,int value){
    Node* n=createNode(value);
    if(head==NULL){
        return n;
    }
    n->next=head;
    head->prev=n;
    head=n;
    return n;
}

Node* insertEnd(Node* head,int value){
    Node* n=createNode(value);
    if(head==NULL){
        return n;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
    return head;
}

Node* insertAfter(Node* head,int after,int value){
    Node* n=createNode(value);
    if(head==NULL){
        return n;
    }
    Node* temp=head;
    while(temp!=NULL && temp->data != after){
        temp=temp->next;
    }
    temp->next->prev=n;
    n->next=temp->next;
    n->prev=temp;
    temp->next=n;
    return head;
}

Node* deleteNode(Node* head,int key){
    if(head==NULL){
        printf("empty\n");
        return NULL;
    }
    Node* temp=head;
    if(temp->data == key){
        head=temp->next;
        head->prev=NULL;
        free(temp);
        return head;
    }
    Node* prev=temp;
    while(temp!=NULL && temp->data!=key){
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    if(temp->next!=NULL){
        temp->next->prev=prev;}

    free(temp);
    return head;
}

void printForward(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void printBackward(Node* head){
    Node* temp=head;
    //sona gidiyoruz
    while(temp->next!=NULL){
        temp=temp->next;
    }
    //print
    do{
        printf("%d ",temp->data);
        temp=temp->prev;
    }while(temp->next!=NULL);
    printf("\n");
}

int main(){
    Node* head=NULL;
    head=insertEnd(head,60);
    head=insertBeg(head,50);
    head=insertEnd(head,80);
    head=insertAfter(head,60,70);
    printForward(head);
}
    printBackward(head);
}
