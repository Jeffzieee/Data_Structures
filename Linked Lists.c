#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *link;
}*newnode=NULL,*tail=NULL,*head=NULL;

int length=0;
void create();
void display();
void insert();
void delete();

void main() {
    int ch;
    while(1){
        printf("\nEnter choice \n1:- Create and Insert Linked List\n2:- Display\n3:-Insert \n4:-Delete \n5:-Exit \n ");
        scanf("%d",&ch);
        if(ch==1) {
            create();
        }
        else if(ch==2){
            display();
        }
        else if(ch==3){
            insert();
        }
        else if(ch==4){
            delete();
        }
        else if(ch==5){
            printf("\n PROGRAM TERMINATED!");
            break;
        }
    }
}

void create(){
    int x,flag=1;
    while(flag==1) {
        printf("\nEnter the data : ");
        scanf("%d", &x);
        newnode = (struct node *) malloc(sizeof(struct node));
        newnode->data = x;
        newnode->link = NULL;
        length++;
        if (head == NULL) {
            head = newnode;
            tail = newnode;
        }
        else{
            tail->link = newnode;
            tail = newnode;
        }
        printf("\nDo you wish to continue? 1-Yes\n2-No");
        scanf("%d",&flag);
    }
}

void display(){
    if(head == NULL){
        printf("\n Linked List doesnt Exist");
        return;
    }
    printf("\n Linked List is :--  ");
    newnode = head;
    while(newnode!=NULL){
        printf("%d->",newnode->data);
        newnode=newnode->link;
    }
    printf("\n");
}

void insert(){
    if(head == NULL){
        printf("\n Linked List doesnt Exist");
        return;
    }
    int pos;
    printf("\nEnter the position you wish to insert : ");
    scanf("%d",&pos);

    if(pos>length || pos<=0){
        printf("\nInvalid position");
        return;
    }
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the node to insert");
    scanf("%d",&newnode->data);
    if(pos==1){
        newnode->link=head;
        head=newnode;
        length++;
        return;
    }
    else if(pos==length){
        newnode->link=NULL;
        tail->link=newnode;
        tail=newnode;
        length++;
        return;
    }
    else {
        struct node *current,*prevnode;
        current = prevnode = head;
        for (int i = 1; i <= pos; i++) {
            prevnode=current;
            current=current->link;
            if (i == pos) {
                prevnode->link=newnode;
                newnode->link=current;
                length++;
                return;
            }

        }
    }
}

void delete(){
    if(head == NULL){
        printf("\n Linked List doesnt Exist");
        return;
    }
    struct node *current,*prevnode;
    prevnode = head;
    int x,flag=0,pos=0;
    printf("\nEnter the element to delete:-");
    scanf("%d",&x);
    current=head;
    while(current!=NULL){
        pos++;
        if(current->data==x){
            flag=1;
            break;
        }
        prevnode=current;
        current=current->link;
    }
    if(flag==0){
        printf("\nElement not found!");
        return;
    }
    else{
        if(pos==1){
            head=head->link;
        }
        else if(pos==length){
            tail=prevnode;
        }
        else{
            prevnode->link=current->link;
        }
        free(current);
        printf("\nDeleted Node %d",x);
        length--;
        return;
    }
}

