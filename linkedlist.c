#include<stdio.h>//standard input output
#include<stdlib.h>//standard lib for handling malloc funct
#include<string.h>//a file to andle strings arrays

struct Node{//a structure for the node
    char name[30];
    int data;
    struct Node* next;//self referential structure
};

void insertAtBeginning(struct Node** head,char pname[],int newdata){//a function to create a node and insert at the beginning
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));

    if(newnode==NULL){
        printf("Memory could not be allocated\n");
        return;
    }
    strcpy(newnode->name,pname);//used to copy the string
    newnode->data=newdata;
    newnode->next=(*head);
    (*head)=newnode;
}

void deleteNode(struct Node** head,int key){
    struct Node* temp=*head;
    struct Node* prev=NULL;

    if(temp != NULL && temp->data == key){//check if the node itself holds the key
        *head=temp->next;//change head
        free(temp);//free old head
        return;
    }
    while(temp != NULL && temp->data != key){//search for the key to be deleted
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){//check if key is not present
        printf("Key could not be found\n");
        return;
    }
    prev->next=temp->next;//if present free the node
    free(temp);
}
void displayList(struct Node* node){// a function to print the list
    while(node!=NULL){
        printf("%s %d->",node->name,node->data);
        node=node->next;
    }
    printf("NULL\n");
}

int main(){
    struct Node* head=NULL;

    int n,data,key;
    char name[30];

    printf("Enter the number of nodes:\n");
    scanf("%d",&n);

    getchar();//clear input buffer before reading strings

    for(int i=1;i<=n;i++){
        printf("Enter the name and the data:\n",i+1);
        scanf("%s %d",name,&data);
        insertAtBeginning(&head,name,data);
    }
    printf("Original list:\n");
    displayList(head);

    printf("Enter the key you want to delete:\n");
    scanf("%d",&key);
    deleteNode(&head,key);

    printf("Modified list:\n");
    displayList(head);

    while(head!=NULL){
        struct Node* temp=head;
        head=head->next;
        free(temp);
    }
    return 0;
}
