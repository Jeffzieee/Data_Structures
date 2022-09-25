#include <stdio.h>

int create_array();
void display(int n);
int insert(int n);
int delete(int n);

int a[10];

void main() {
    int n = 0, ch;

    while(1){
       printf("\nEnter choice \n1:- Create and Insert Array\n2:- Display\n3:-Insert \n4:-Delete \n5:-Exit \n ");
       scanf("%d",&ch);
       if(ch==1) {
         n = create_array();
       }
       else if(ch==2){
            display(n);
       }
       else if(ch==3){
           n = insert(n);
       }
       else if(ch==4){
           n = delete(n);
       }
       else if(ch==5){
           printf("\n PROGRAM TERMINATED!");
           break;
       }
    }
    }

int create_array(){
    int i,n;
    do {
        printf("\nEnter array size: ");
        scanf("%d", &n);
        if (n > 10)
            printf("\nArray out of Bounds");
    } while (n > 10);
    for (i = 0; i<n; i++) {
        printf("\nEnter element %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    return n;
}

void display(int n){
    for(int i =0; i<n; i++) {
        printf("\nElement %d: %d", i + 1, a[i]);
    }
}

int insert(int n){
    int num,pos;
    printf("\n Enter the number to insert :- ");
    scanf("%d",&num);
    printf("\nEnter the position to insert :- ");
    scanf("%d",&pos);

    for(int i=n;i>=pos;i--){
        a[i]=a[i-1];
    }
    a[pos-1] = num;
    return n+1;
}

int delete(int n){
    int num,pos,flag=0;
    printf("\nEnter the number you wish to delete :");
    scanf("%d",&num);
    for(int i=0;i<n;i++){
        if(a[i]==num){
            printf("\nElement %d found at position:- %d",num,i+1);
            pos = i;
            flag=1;
            break;
        }
    }
    if(flag){
        for(int i=pos;i<n;i++){
            a[i]=a[i+1];
            if(i==n-1){
                a[i]=0;
            }
        }
    }
    return n-1;
}


