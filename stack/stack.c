#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *nextNode;
};

struct Stack{
    struct node *head;
};

struct node *createNode(int key){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = key;
    newnode->nextNode = NULL;
}

int isEmpty(struct Stack S){
    if(S.head == NULL) return 1;
    else return 0;
}

int frontStack(struct Stack S){
    if(!isEmpty(S)){
        return S.head->data;
    }
    else{
        printf("Stack is Empty\n");
        return 0;
    } 
}

void push(struct Stack *S, int key){
    struct node *temp = createNode(key);
    if(isEmpty(*S)){
        S->head = temp;
    }
    else{
        temp->nextNode = S->head;
        S->head = temp;
    }
}

void pop(struct Stack *S){
    if(!isEmpty(*S)){
        struct node *temp = S->head;
        S->head = S->head->nextNode;
        temp->nextNode = NULL;
        free(temp);
    }
    else printf("Stack is Empty\n");
}

void printStack(struct Stack S){
    struct node *temp = S.head;
    if(!isEmpty(S)){
        while(temp){
            printf("%d ",temp->data);
            temp = temp->nextNode;
        }
        printf("\n");
    }else printf("Stack is Empty\n");
}

int main(){

    struct Stack S;
    S.head = NULL;

    for(int i=1; i<=10; i++){
        push(&S, i);
    }
    printStack(S);
    
    pop(&S);
    pop(&S);
    pop(&S);
    pop(&S);
    pop(&S);
    pop(&S);
    pop(&S);
    pop(&S);
    pop(&S);
    pop(&S); 
    push(&S,10);  
    printf("%d\n",frontStack(S));
    printStack(S);
    return 0;
}