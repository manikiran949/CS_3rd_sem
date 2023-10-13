#include<stdio.h>
#include<stdlib.h>
struct linkedlist{
	int data;
	struct linkedlist *next;
};
typedef struct linkedlist node;
node *deleteAtFirst(node *start){
	node *temp=start->next;
	free(start);
	return temp;
}
node* deleteNo(node *start,int n){
	if(start==NULL) return start;
	node *tmp=start;
	node *prev=NULL;
	while(tmp->data!=n && tmp->next!=NULL){
		prev=tmp;
		tmp=tmp->next;
	}
	if(tmp->next==NULL && tmp->data!=n) return start;
	prev->next=tmp->next;
	free(tmp);
	return start;
}
node *deleteAtLast(node *start){
	if(start==NULL) return start;
	node *tmp=start;
	node *prev=NULL;
	while(tmp->next!=NULL){
		prev=tmp;
		tmp=tmp->next;
	}
	prev->next=NULL;
	free(tmp);
	return start;
}
node* insertAtFirst(node *start,int n){
	node *temp=(node *)malloc(sizeof(node));
	temp->data=n;
	if(start==NULL){
		temp->next=NULL;
		return temp;
	}
	temp->next=start;
	return temp;
}
void show(node *start){
	while(start!=NULL){
		printf("%d -> ",start->data);
		start=start->next;
	}
	printf("NULL\n");
}
int main(){
	node *start=NULL;
	start=insertAtFirst(start,5);
	start=insertAtFirst(start,4);
	start=insertAtFirst(start,3);
	start=insertAtFirst(start,2);
	start=insertAtFirst(start,1);
	show(start);
	start=deleteAtFirst(start);
	show(start);
	start=deleteNo(start,3);
	show(start);
	start=deleteAtLast(start);
	show(start);
	return 0;
}
