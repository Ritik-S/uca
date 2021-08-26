#include<stdio.h>
#include <stdlib.h>
struct queue_node{
	int data ;
	struct queue_node *next; 
};
//head is where dequeue operation will occur tail is where enqueue operation will occur
struct queue_node *head = NULL;
struct queue_node *tail = NULL;
//function to enqueue new element in queue
void enqueue(int val)
{
	struct queue_node *temp = (struct queue_node*)malloc(sizeof(struct queue_node));
        temp -> data = val;
        //if head == NULL means the node is start of linked list else it it a new node in queue
	if(head == NULL)
	{
	   head = temp;
	   tail = temp;
	   temp -> next = NULL;
	}
	else
	{
	   tail -> next = temp;
	   tail = temp;
	   temp -> next = NULL;
	}
	  
}
//function to dequeue front of queue
int dequeue()
{ 
        //queue is empty nothing to be dequeued
	if(head == NULL)
	return -1;
	int element = -1;
	//According to fifo technique head element came before all other elements so we deque head element
	if(tail == head)
	{
		element = tail -> data;
		tail = NULL;
		head = NULL;
	}
	else
	{
		//head is removed and variable removed is just to free space to dequeued element
		struct queue_node *removed = head;
		element = head -> data;
		head=head -> next;
		free(removed);
		
	}
	return element; 
}
//function to return peek element
int peek()
{
	
	if(head == NULL)
	return -1;
	return head -> data;
}
//to check is queue is empty or not
int is_empty()
{
	if(head == NULL)
	return 1;
	else
	return 0;
}
int main()
{
	enqueue(1);
	enqueue(2);
	struct queue_node *print=head;
	while(print != NULL)
	{
		printf("%d\n",print -> data);
		print=print -> next;
	}
	printf("Peek element is %d\n",peek());
	dequeue();
	//print is just used to print the queue
        print = head;
	while(print != NULL)
	{
		printf("%d\n",print -> data);
		print = print -> next;
	}
	
	if(is_empty())
         printf("YES\n");
	else
	 printf("NO\n");
	 
	dequeue();
	
	if(is_empty())
         printf("YES\n");
	else
	 printf("NO\n");
	 
	enqueue(1);
	print = head;
	while(print != NULL)
	{
		printf("%d\n",print -> data);
		print = print -> next;
	}
	
        printf("Peek element is %d\n",peek());
}
