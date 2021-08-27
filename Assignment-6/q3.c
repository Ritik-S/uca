/*
 * Program to implement deque
 * 
 * Compilation : gcc q3.c
 * Execution : ./a.out
 *
 * @Ritik  , (1910990138) , 23/08/21 .
 * Assignment_6
 */
#include<stdio.h>
#include<stdlib.h>
struct node
{
        int data;
	struct node *next;
};
struct node *head = NULL , *tail = NULL;
//function needed when we need to enqueue at head
void enqueue_head(int value)
{
	struct node *new_node=(struct node*)malloc(sizeof(struct node));
	new_node -> next = NULL;
	new_node -> data=value;
	//if head is null then tail is also null
	if(head == NULL)
	{
		head = new_node;
		tail = new_node;
	}
	//changing head to new node inserted behind previous head
	else
	{
	        new_node -> next = head;
	        head = new_node;
	}
}
//function needed when we need to enqueue at tail
void enqueue_tail(int value)
{
	
	struct node *new_node=(struct node*)malloc(sizeof(struct node));
	new_node -> next = NULL;
	new_node -> data = value;
	//if tail is null head is also null
	if(tail == NULL)
	{
		head = new_node;
		tail = new_node;
	}
	//adding new node next to tail and making it new tail
	else
	{
		tail -> next = new_node;
		tail = tail -> next;
	}
}
//function needed when we need to dequeue at head
int dequeue_head()
{
	if(head == NULL)
	return -1;
	if(head == tail)
	{
		tail = NULL;
	}
	//simply moving head one step forward so this will be new head
        int val = head -> data;
        struct node *removed=head;
	head = head -> next;
        free(removed);
        return val; 
}
//function needed when we need to dequeue at tail
int dequeue_tail()
{
	if(tail == NULL)
	return -1;
	int val = tail -> data;
	//handling case when there is just one node in deque
	if(head == tail)
	{
	    head = NULL;
	    struct node *removed = tail;
            tail = tail -> next;
            free(removed);
            return val; 
	}
	
	struct node *pointer = head;
	//reaching just one node behind tail and removing tail node and our current position node is our new tail
	while(pointer -> next != tail)
	{
		pointer = pointer -> next;
	}
	struct node *removed = tail;
	tail = pointer;
	tail -> next = NULL;
	free(removed);
	return val ;
	
}
//function to find peek head
int peek_head()
{
	if(head == NULL)
	return -1;
	return head -> data;
}
//function to find peek tail
int peek_tail()
{
	if(tail == NULL)
	return -1;
	return tail -> data;
}
//functin to check if deque is empty or not
int is_empty()
{
	if(head == NULL && tail == NULL)
	return 1;
	else
	return 0;
}
//function to find if some element is present or not
int is_present(int value)
{
	struct node *checker = head;
	//just moving in linked list to find if the element is present or not
	while(checker != NULL)
	{
		if(checker -> data == value)
		return 1;
		checker = checker -> next;
	}
	return 0;
}

int main()
{
	
	enqueue_head(1);
	enqueue_head(2);
	enqueue_tail(3);
	enqueue_tail(4);
	struct node *printer =head;
	//printing deque
	while(printer != NULL)
	{
		printf("%d\n", printer->data);
		printer = printer -> next;
	}
	printf("head value is: %d\n",head -> data);
	printf("tail value is: %d\n",tail -> data);
	dequeue_head();
	dequeue_tail();
	printer = head;
	while(printer != NULL)
	{
		printf("%d\n",printer -> data);
		printer = printer -> next;
	}
	printf("head value is: %d\n",head -> data);
	printf("tail value is: %d\n",tail -> data);
	if(is_present(3))
	{
		printf("Yes 3 is present\n");
	}
	else
	{
		printf("NO 3 is not present\n");
	}
	if(is_present(2))
	{
		printf("Yes 2 is present\n");
	}
	else
	{
		printf("No 2 is not present\n");
	}		
	if(is_empty())
	{
		printf("Yes deque is empty\n");
	}
	else
	{
		printf("No deque is not empty\n");
	}	
	dequeue_head();
	dequeue_head();
	if(is_empty())
	{
		printf("Yes deque is empty\n");
	}
	else
	{
		printf("No deque is not empty\n");
	}	
}
