/*
 * Program to check if it is palindromic linked list
 * 
 * Compilation : gcc q4.c
 * Execution : ./a.out
 *
 * @Ritik  , (1910990138) , 23/08/21 .
 * Assignment_6
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

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

bool isPalindrome(struct ListNode* head){
    
    struct stack *node=NULL;
    if(head==NULL)
        return true ;
    if(head->next==NULL)
        return true; 
    struct ListNode* root= head;
    int size = 0;
    //calculating the size of linked list
    while(root!=NULL)
    {
        
        size++;
        root=root->next; 
    }
    root=head;
    //it represents position of current node
    int i =0;
    
    while(root!=NULL)
    {
        //if the root node is in the first half of the linked list add it to stack        
        if(i<size/2)
        {
            push(&node,root->val);
        }
        //if the root node is in the second half of the linked list pop the stack and popped element should be equal to
        //current element
        else if(i>=(size+1)/2)
        {
            if(pop(&node)!=root->val)
            {
                return false; 
            }
        }
        i++;
        root=root->next; 
    }
    return true; 
    
    

}
