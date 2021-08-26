/*
 * Program to implement stack using linked list.
 * 
 * Compilation : gcc q1.c
 * Execution : ./a.out
 *
 * @Ritik Sedana , (1910990138) , 23/08/21 .
 * Assignment_6
 */
#include<stdio.h>
#include<stdlib.h>
//our new linked list stack
struct stack
{
    int data;
    struct stack *next;
    	
};
//push function add new node at the end
void push(struct stack **head,int val)
{
   
    
    struct stack *temp_stack=(struct stack*)malloc(sizeof(struct stack));
    //making new node to be pushed
    temp_stack->data=val;
    temp_stack->next=NULL;
    //adding node if already some node is existing
    if(head!=NULL)
    temp_stack->next=*head;
    //if no node is there this will be our first node
    *head=temp_stack;
}
//pop shifts head to the next node and returns value of the popped node
int pop(struct stack **head)
{
    
    struct stack *temp_node=*head;
    
    if(temp_node==NULL)
    return -1;
    //simply using two pointers of type struct stack* to find out which node is to be returned
    int val=temp_node->data;
    temp_node=*head;
   
    struct stack *head2=*head;
    head2=head2->next;
    *head=head2;
    
    temp_node->next=NULL;
    free(temp_node);
    

    return val;
}
//function to return peek element
int peek(struct stack *head)
{
    if(head==NULL)
    return -1;
    else
    return head->data;
}
//function to check if stack is empty or not
int is_empty(struct stack *head)
{
    
    
    if(head==NULL)
    return 1;
    else
    return 0;
}


int main() {
    struct stack *node=NULL;
    push(&node,1);
    push(&node,2);
    
    
    printf("Elements of LinkList :\n");
    struct stack* answer=node;
    while(answer!=NULL)
    {
        printf("%d\n",answer->data);
        answer=answer->next;
    }
    
    printf("Peek Element is %d\n",peek(node));
    if(is_empty(node))
    printf("YES\n");
    else
    printf("NO\n");
    
    pop(&node);
    pop(&node);
    
    if(is_empty(node))
    printf("YES\n");
    else
    printf("NO\n");
    push(&node,1);
    push(&node,2);
    printf("Elements of LinkList :\n");
    answer=node;
    while(answer!=NULL)
    {
        printf("%d\n",answer->data);
        answer=answer->next;
    }
    
    printf("Peek Element is %d\n",peek(node));
    return 0;
}
