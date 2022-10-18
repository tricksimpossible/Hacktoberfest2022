//Circular queue using single linked list

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node * next;
}*front=NULL,*rear=NULL;

void traversal();

void enqueue(int val)
{
    struct node * new;
    new=(struct node *)malloc(sizeof(struct node));
    new->info=val;
    new->next=NULL;
    if(front==NULL && rear==NULL)
    {
        front=new;
        rear=new;
        rear->next=front;
    }
    else
    {
        rear->next=new;
        rear=new;
        new->next=front;
    }
}

void dequeue()
{
    int val;
    struct node * temp;
    if(front==NULL && rear==NULL)
    {
        printf("UNDERFLOW");
        return;
    }
    if(front==rear)
    {
        temp=front;
        val=front->info;
        front=NULL;
        rear=NULL;
        free(temp);
    }
    else
    {
        temp=front;
        val=front->info;
        front=front->next;
        rear->next=temp->next;
        free(temp);
    }
}

void traversal()
{
    struct node * ptr=front;
    while(ptr!=rear)
    {
        printf("%d\n",ptr->info);
        ptr=ptr->next;    
    }
    printf("%d\n",ptr->info);
}

int main()
{

    int val;
    char ch;
    printf("Do you want to enqueue: (y/n) ");
    scanf(" %s",&ch);
    while(ch=='y')
    {
        printf("Enter the value: ");
        scanf("%d",&val);
        enqueue(val);
        printf("Do you want to enqueue: (y/n) ");
        scanf(" %s",&ch);
    }
    traversal();

    printf("Calling Dequeue: \n");
    dequeue();
    printf("Calling Dequeue: \n");
    dequeue();

    traversal();

    printf("Calling Dequeue: \n");
    dequeue();

    traversal();
    return 0;
}