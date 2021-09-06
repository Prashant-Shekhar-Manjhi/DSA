#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *nextNode,*prevNode;
};

struct list{
    struct node *head, *tail;
    int size;
};

struct node *createNode(int key){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = key;
    newnode->nextNode = NULL;
    newnode->prevNode = NULL;
    return newnode;
};

int isEmpty(struct list L){
    if(L.head == NULL && L.tail == NULL) return 1;
    else return 0;
}


struct node *nthElement(struct list L, int n){
    struct node *temp = L.head;
    int i=1;
    if(!isEmpty(L)){
        while(temp && i < n){
            temp = temp->nextNode;
            i++;
        }
        if(i == n) return temp;
    }
    return NULL;
}


int listSize(struct list L){
    int count = 0;
    struct node *temp = L.head;
    if(!isEmpty(L)){
        while(temp){
            count++;
            temp = temp->nextNode;
        }
    }
    return count;    
}


void insert_front(struct list *L, int key){
    struct node *newnode = createNode(key);
    struct node *temp;
    if(isEmpty(*L))
    {
        L->head = newnode;
        L->tail = newnode;
    }
    else{
        temp = L->head;
        newnode->nextNode = temp;
        temp->prevNode = newnode;
        L->head = newnode;
    }
}


void insert_back(struct list *L,int key){
    struct node *newnode = createNode(key);
    struct node *temp;
    if(isEmpty(*L))
    {
        L->head = newnode;
        L->tail = newnode;
    }
    else{
        temp = L->tail;
        temp->nextNode = newnode;
        newnode->prevNode = temp;
        L->tail = newnode;
    }
}


void insertAt(struct list *L, int key, int pos){
    struct node *temp;
    int size = listSize(*L);
    if(!isEmpty(*L)){
        if(size == 1){
            if(pos == 1) insert_front(L,key);
            else if(pos == 2) insert_back(L,key);
            else printf("<--Invalid Position-->"); 
        }
        else if((size+1) == pos)
            insert_back(L,key);
        else if(pos <= size){
            temp = nthElement(*L, pos);
            struct node * newnode = createNode(key);
            newnode->nextNode = temp;
            newnode->prevNode = temp->prevNode;
            temp->prevNode->nextNode = newnode;
            temp->prevNode = newnode;
        }
        else printf("<--Invalid Position-->\n");
    }else{
        insert_front(L,key);
    }
}


void delete_front(struct list *L){
    struct node *temp;
    if(!isEmpty(*L)){
        if(L->head == L->tail){
            temp = L->head;
            L->head = NULL;
            L->tail = NULL; 
            free(temp);
        }
        else{
            temp = L->head;
            L->head = L->head->nextNode;
            temp->nextNode = NULL;
            L->head->prevNode = NULL;
            free(temp);
        }
    }
    else printf("-1\n");
}


void delete_back(struct list *L){
    struct node *temp;
    if(!isEmpty(*L)){
        if(L->head == L->tail){
            temp = L->head;
            L->head = NULL;
            L->tail = NULL;
            free(temp);
        }
        else{
            temp = L->tail;
            L->tail = L->tail->prevNode;
            L->tail->nextNode = NULL;
            temp->prevNode = NULL;
            free(temp);
        }
    }
    else printf("-1\n");
}


void printList(struct list L){
    struct node *temp = L.head;
    if(!isEmpty(L)){
        while(temp){
            printf("%d ",temp->data);
            temp = temp->nextNode;
        }
        printf("\n");
    }
    else printf("Empty list....\n");
}



void deleteAt(struct list *L, int pos){
    struct node *temp = nthElement(*L,pos);
    if(temp){
        if(temp->prevNode == NULL){
            delete_front(L);
        }
        else if(temp->nextNode == NULL){
            delete_back(L);
        }
        else{
            temp->prevNode->nextNode = temp->nextNode;
            temp->nextNode->prevNode = temp->prevNode;
            temp->nextNode = NULL;
            temp->prevNode = NULL;
            free(temp);
        }
    }else printf("-1\n");
}


int main(){
    struct list L;
    L.head = NULL;
    L.tail = NULL;
    L.size = 0;
    insertAt(&L,100,16);
    insertAt(&L,200,1);
    insertAt(&L,300,3);
    insertAt(&L,400,2);
    insert_front(&L,900);
    insert_back(&L,1000);
    insert_front(&L,599);



    printList(L);
    printf("Size: %d\n",listSize(L));

}