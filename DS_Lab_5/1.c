#include <stdio.h>
#include <stdlib.h>
struct linkedlist
{
    int data;
    struct linkedlist *next;
};

typedef struct linkedlist Node;

Node *insertAtFirst(Node *start, int n)
{
    Node *temp=(Node *)malloc(sizeof(Node));
    temp->data=n;
    if(start==NULL)
    {
        temp->next=NULL;
        return temp;
    }
    temp->next=start;
    return temp;
}

Node *insertAtLast(Node *start, int n)
{
    Node *temp=(Node *)malloc(sizeof(Node));
    temp->data=n;
    if(start==NULL)
    {
        temp->next=NULL;
        return temp;
    }
    Node *tmp=start;
    while(tmp->next!=NULL)
    {
        tmp=tmp->next;
    }
    tmp->next=temp;
    temp->next=NULL;
    return start;
}

Node *insertAfter(Node *start, int k, int n)
{
    Node *temp=(Node *)malloc(sizeof(Node));
    temp->data=n;
    if(start==NULL)
    {
        temp->next=NULL;
        return temp;
    }
    Node *tmp=start;
    while(tmp->data!=k&&tmp->next!=NULL)
    {
        tmp=tmp->next;
    }
    if(tmp->next==NULL)
    {
        tmp->next=temp;
        temp->next=NULL;
        return start;
    }
    else
    {
        temp->next=tmp->next;
        tmp->next=temp;
        return start;
    }
}
Node *insertBefore(Node *start, int k, int n)
{
    Node *temp=(Node *)malloc(sizeof(Node));
    temp->data=n;
    if(start==NULL)
    {
        temp->next=NULL;
        return temp;
    }
    Node *tmp=start;
    Node *prev;
    while(tmp->data!=k&&tmp->next!=NULL)
    {
        prev=tmp;
        tmp=tmp->next;
    }
    if(tmp->next==NULL && tmp->data!=k)
    {
        tmp->next=temp;
        temp->next=NULL;
        return start;
    }
    else
    {
        prev->next=temp;
        temp->next=tmp;
        return start;
    }
    
}
void show(Node *start)
{
    while(start!=NULL)
    {
        printf("%d->",start->data);
        start=start->next;
    }
    printf("NULL");
}

int main()
{
    Node *start=NULL;
    int n=10,i=0;
    while(i<10)
    {
        start=insertAtFirst(start,i+1);
        i++;
    }
    printf("\nThe list is:\n");
    show(start);
    start=insertAtLast(start,15);
    printf("\nInsert at last:\n");
    show(start);
    start=insertAfter(start,6,14);
    printf("\nInsert after:\n");
    show(start);
    start=insertBefore(start,6,12);
    printf("\nInsert before:\n");
    show(start);
    return 0;
}
