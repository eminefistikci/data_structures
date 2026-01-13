#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int isEmpty(Node* head){
    if(head==NULL){
        return 1;
    }
    return 0;
}

Node* insertBeg(Node* head,int value){
    Node* n=createNode(value);
    if(isEmpty(head)){
        n->next=n;
        n->prev=n;
        return n;
    }
    n->next=head;
    head->prev=n;
    //sonunu başa bağlıcaz
    Node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
    head=n;
    return head;
}

Node* insertEnd(Node* head,int value){
    Node* n=createNode(value);
    if(isEmpty(head)){
        n->next=n;
        n->prev=n;
        return n;
    }
    Node* temp=head;
    //sona gidelim
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
    n->next=head;
    head->prev=n;
    return head;
}

Node* insertAfter(Node* head, int after, int value){
    Node* n=createNode(value);
    if(isEmpty(head)){
        printf("empty");
        n->next=n;
        n->prev=n;
        return n;
    }
    Node* temp=head;
    do{
        temp=temp->next;
    }while(temp!=head && temp->data!=after);

    n->next=temp->next;
    temp->next->prev=n;
    temp->next=n;
    n->prev=temp;
    return head;

}

Node* deleteNode(Node* head,int key){
    if(isEmpty(head)){
        return NULL;
    }
    Node* temp=head;
    Node* tail=head->prev;

    if(temp->data == key){
        head=temp->next;
        tail->next=head;
        head->prev=tail;
        return head;
    }
    Node* prev=temp;
    do{
        prev=temp;
        temp=temp->next;
    }while(temp!=head && temp->data!=key);
    prev->next=temp->next;
    if(temp->next!=NULL){
        temp->next->prev=prev;}
    free(temp);
    return head;
}

void printForward(Node* head){
    Node* temp=head;
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=head);
    printf("\n");
}

void printBackward(Node* head){
    Node* temp=head->prev;
    Node* tail=head->prev;
    do{
        printf("%d ",temp->data);
        temp=temp->prev;
    }while(temp!=tail);

    printf("\n");
}

//baştan itibaren N. sıradaki elemanı silen fonksiyon yaz:
int countNode(Node* head){
    int count=0;
    Node* temp=head;
    do{
        count++;
        temp=temp->next;
    }while(temp!=head);
    return count;
}

Node* delete_Nth(Node* head,int N){
    int count=countNode(head);
    int find=1;
    if(N>count){
        printf("N is more than the number of list elements\n");
        return head;
    }
    Node* temp=head;
    Node* iter=head;
    //liste sonunu bul
    while(temp->next!=head){
        temp=temp->next;
    }
    if(N==1){
        temp->next=iter->next;
        iter->next->prev=temp;
        head=iter->next;
        free(iter);
        return head;
    }
    Node* prev=temp;
    do{
        prev=temp;
        temp=temp->next;
        find++;
    }while(find!=N);

    prev->next=temp->next;
    temp->next->prev=prev;
    free(temp);
    return head;
}

int main(){
    Node* head=NULL;
    head=insertBeg(head,2);
    head=insertEnd(head,4);
    head=insertEnd(head,6);
    head=insertAfter(head,4,5);
    printForward(head);
    printBackward(head);
    head=delete_Nth(head,3);
}
    printBackward(head);
}
