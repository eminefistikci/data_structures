#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* right;
    struct Node* left;
};

void case1(struct Node *n);
void case2(struct Node *n);
void case3(struct Node *n);
void case4(struct Node *n);
void case5(struct Node *n);

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value){
    if(root==NULL){
        return createNode(value);
    }
    
    if(value > root->data){
        root->right = insert(root->right, value);
    }else if(value < root->data){
        root->left = insert(root->left, value);
    }
    return root;
}




void inOrder(struct Node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

void preOrder(struct Node* root){
    if(root!=NULL){
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void PostOrder(struct Node* root){
    if(root!=NULL){
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d ",root->data);
    }
}



int findMin(struct Node* root){
    if(root == NULL){
        return -1;
    }

    while(root->left != NULL){
        root = root->left;
    }

    return root->data;
}


int findMax(struct Node* root) {
    if (root == NULL) {
        return -1;
    }

    while (root->right != NULL) {
        root = root->right;
    }

    return root->data;
}


struct Node* search(struct Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }

    if (value < root->data) {
        return search(root->left, value);
    }
    else {
        return search(root->right, value);
    }
}

struct Node* deleteNode(struct Node* root, int key){
    if(root == NULL) return root;

    if(key < root->data){
        root->left = deleteNode(root->left, key);
    }
    else if(key > root->data){
        root->right = deleteNode(root->right, key);
    }
    else if(key == root->data){
        // Tek çocuk veya çocuksuz durumlar (Aynı kalıyor)
        if(root->left == NULL){
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        //iki çocuklu
        int minValue = findMin(root->right); 

        root->data = minValue;

        root->right = deleteNode(root->right, minValue);
    }
    return root;
}

int main() {
    struct Node* root = NULL;

    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 14);

    printf("Inorder: ");
    inOrder(root);

    printf("\nMin: %d", findMin(root));
    printf("\nMax: %d", findMax(root));

    return 0;
}
