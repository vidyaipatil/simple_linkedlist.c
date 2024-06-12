#include<stdio.h>
#include<stdlib.h>

//creating the structure for node
struct node{
	int data;
	struct node*next;
};
//defining the function for insertion at head side
struct node* insert_front(struct node*head,int d){

	struct node*temp=(struct node*)malloc(sizeof(struct node)); //allocating the dynamic memory 
	temp->data=d; // setting the data part 
	temp->next=0; //here 0 is considered as NULL
	if(head==0){  // if LL is empty
		head=temp;
		return head;
		
	}
	else{     // If atleast one node present in LL
		temp->next=head;
		head=temp;
		return head;
	}
}
//defining the function for deletion of node from front
struct node* delete_front(struct node*head){

    if(head==0){    //if LL is empty
		printf("nothing for deletion\n");
		return ;
	}
    else{

	struct node*temp=head;
	head=head->next;
	free(temp); // realese the acquired memory 
	return head;
    }
}
// defining the function for insertion of node at tail
struct node* insert_end(struct node*head,int d){

	struct node*temp=(struct node*)malloc(sizeof(struct node));
	struct node*n;
	temp->data=d;
	temp->next=0;
	if(head==0){ // if LL is empty
		head=temp;
		return head;
	}
	n=head;
	while(n->next!=0){  //Travels the LL until we get last node
		n=n->next;
	}
	n->next=temp;
	return head;
}
// defining the function for deletion of node from the End
void delete_end(struct node*head){
	struct node*temp;
	if(head==0){  //If LL is empty
		printf("nothing for deletion\n");
		return ;
	}
	else{
	while(head->next->next!=0){  // Travels untill the Second last node of LL
		head=head->next;
	}
	temp=head->next;  //Set the temp at last node
	 head->next=0;
	 free(temp);  // Realese the memory
		
	}
}
// Defining the function for insertion at the given position 
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
	for(i=1;i<p-1;i++){ //Travel untill one node before the given position
		n=n->next;
	}
	temp->next=n->next;
	n->next=temp;
}
//Defining the function for deletion of node at given position
void delete_pos(struct node**head,int p){
	int i=0;
	if(p==1){
	  *head=delete_front(*head);	
	}
	struct node*temp;
	struct node*n;
	for(i=1;i<p-1;i++){  //Travel untill one node before the given position
		n=n->next;
	}
	temp=n->next;
	n->next=temp->next;
	free(temp);  //Release the memory
}
// Defining the function for printing the LL
void display(struct node*head){
	if(head==0){
		printf("Linked list is empty\n");
		return ;
	}
	else{
        printf("\n---------------------------Linked List is---------------------------------\n");
		while(head!=0){  //travels the whole LL
			printf("The element is : %d\n",head->data);
			head=head->next;
		}
        printf("\n------------------------------------------------------------------------\n");
		
	}
}
int main(){
	int choice,pos,val;
	char ch;
	struct node*head=(struct node*)malloc(sizeof(struct node));
	head=0;
	
    do{
        printf("\n------------------------------------------------------------------------\n");
    	printf("Enter your choice among the following\n");
	printf("1.insert at first\n2.insert at end\n3.insert at position\n4.delete at front\n5.delete at end\n6.delete at position\n");
    printf("\n------------------------------------------------------------------------\n");
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