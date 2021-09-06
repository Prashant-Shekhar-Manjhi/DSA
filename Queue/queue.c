#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *nextNode;
};

struct Queue{
    struct node *head;
    struct node *tail;
};

int isEmpty(struct Queue Q){
    if(Q.head == NULL && Q.tail == NULL) return 1;
    else return 0;
}

struct node *createNode(int key){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = key;
    newnode->nextNode = NULL;
    return newnode;
}

void enQueue(struct Queue *Q,int key){
    struct node *newnode = createNode(key);
    if(isEmpty(*Q)){
        Q->head = newnode;
        Q->tail = newnode;
    }
    else{
       Q->tail->nextNode = newnode;
       Q->tail = newnode;
    }
}

struct node * deQueue(struct Queue *Q){
    struct node *temp = NULL;
    if(!isEmpty(*Q)){
        if(Q->head == Q->tail){
            temp = Q->head;
            Q->head = NULL;
            Q->tail =NULL;
        }else{
            temp = Q->head;
            Q->head = Q->head->nextNode;
            temp->nextNode = NULL;
        }   
    }
    return temp;
}



void printQueue(struct Queue Q){
    if(!isEmpty(Q)){
        struct node *temp = Q.head;
        while(temp){
            printf("%d ",temp->data);
            temp = temp->nextNode;
        }
    }
    else printf("Empty Queue...");
    printf("\n");
}


int main(){
    struct Queue Q;
    Q.head = NULL;
    Q.tail = NULL;

    for(int i=0; i<10; i++){
        enQueue(&Q,i);
    }
    printQueue(Q);

    deQueue(&Q);
    enQueue(&Q,100);
    deQueue(&Q);
    deQueue(&Q);
    deQueue(&Q);
    deQueue(&Q);
    deQueue(&Q);
    deQueue(&Q);
    deQueue(&Q);
    deQueue(&Q);
    deQueue(&Q);
    deQueue(&Q);
    deQueue(&Q);
    enQueue(&Q ,55);
    enQueue(&Q, 110);

    printQueue(Q);
    return 0;
}