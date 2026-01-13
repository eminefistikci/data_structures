#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void insert_head(struct Node** head,int value){
    struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
    new_node->data=value;
    if(*head==NULL){
        new_node->next=new_node;
        *head=new_node;
        return;
    }
    else{
    new_node->next=*head;}

    struct Node* temp=*head;

    while(temp->next!=*head){
        temp=temp->next;
    }
    temp->next=new_node;
    *head=new_node;
}

void insert_end(struct Node** head,int value){
    struct Node* temp=*head;
    struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
    new_node->data=value;

    while(temp->next!=*head){
        temp=temp->next;
    }
    temp->next=new_node;
    new_node->next=*head;

}


void print_list(struct Node* head){
    struct Node* temp=head;
    do{
        printf("%d -> ",temp->data);
        temp=temp->next;
    }while(temp != head);
    printf("%d...",head->data);
}

int main(){
    struct Node* head=NULL;
    insert_head(&head,5);
    insert_head(&head,25);
    insert_end(&head,60);
    print_list(head);
}
