#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node*next;
};
struct node* insert_front(struct node*head,int d){
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	temp->data=d;
	temp->next=0;
	if(head==0){
		head=temp;
		return head;
		
	}
	else{
		temp->next=head;
		head=temp;
		return head;
	}
}
struct node* delete_front(struct node*head){
	struct node*temp=head;
	head=head->next;
	free(temp);
	return head;
}
struct node* insert_end(struct node*head,int d){
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	struct node*n;
	temp->data=d;
	temp->next=0;
	if(head==0){
		head=temp;
		return head;
	}
	n=head;
	while(n->next!=0){
		n=n->next;
	}
	n->next=temp;
	return head;
}
void delete_end(struct node*head){
	struct node*temp;
	if(head==0){
		printf("There is nothing for deletion\n");
		return ;
	}
	else{
	while(head->next->next!=0){
		head=head->next;
	}
	temp=head->next;
	 head->next=0;
	 free(temp);
		
	}
}
void insert_pos(struct node**head,int data,int p){
	int i;
	if(p==1){
		*head=insert_front(*head,data);
		return ;
	}
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	struct node*n;
	n=*head;
	for(i=1;i<p-1;i++){
		n=n->next;
	}
	temp->next=n->next;
	n->next=temp;
}
void delete_pos(struct node**head,int p){
	int i=0;
	if(p==1){
	  *head=delete_front(*head);	
	}
	struct node*temp;
	struct node*n;
	for(i=1;i<p-1;i++){
		n=n->next;
	}
	temp=n->next;
	n->next=temp->next;
	free(temp);
}
void display(struct node*head){
	if(head==0){
		printf("Linked list is empty\n");
		return ;
	}
	else{
		while(head!=0){
			printf("The element is : %d\n",head->data);
			head=head->next;
		}
		
	}
}
int main(){
	int choice,pos,val;
	char ch;
	struct node*head=(struct node*)malloc(sizeof(struct node));
	head=0;
	
    do{
    	printf("Enter your choice among the following\n");
	printf("1.insert at first\n2.insert at end\n3.insert at position\n4.delete at front\n5.delete at end\n6.delete at position\n");
    scanf("%d",&choice);
    	switch(choice){
    		case 1:{
    			printf("Enter the value which you want to insert\n");
    			scanf("%d",&val);
    			head=insert_front(head,val);
    			display(head);
    			break;
    		}
    		case 2:{
		
    		printf("Enter the value which you want to insert\n");
    			scanf("%d",&val);
    			head=insert_end(head,val);
    			display(head);
    			break;
	       }
	       	case 3:{
			
    		printf("Enter the value which you want to insert\n");
    			scanf("%d",&val);
    		printf("Enter the position at which you want to insert\n");
    		scanf("%d",&pos);
    		
    			insert_pos(&head,val,pos);
    			display(head);
    			break;
	       }
	       case 4:{
		
    			head=delete_front(head);
    			display(head);
    			break;
    		}
    		case 5:{
    			delete_end(head);
    			display(head);
    			break;
    		}
    		case 6:{
    		printf("Enter the position at which you want to insert\n");
    		scanf("%d",&pos);
    		
    			delete_pos(&head,pos);
    			display(head);
    			break;
    	}
    	
    	
	
	}
		printf("Do want to repeate it press the key C\n");
    	scanf(" %c",&ch);
}while(ch=='c' || ch=='C');
return 0;
}