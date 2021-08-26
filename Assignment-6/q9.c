/*
 * Program to Rotate List.
 * 
 * Compilation : gcc q9.c
 * Execution : ./a.out
 *
 * @Ritik , (1910990138) , 23/08/21 .
 * Assignment_6
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){
    //handling edge cases    
    if(head==NULL||k==0)
        return head; 
    //root is just to traverse the linked list
    struct ListNode* root = head; 
    //begin is to mark the start point of linked list as head is going to change soon
    struct ListNode* begin = head; 
    //size of linked list
    int size = 0;
    while(root!=NULL)
    {
        root=root->next;
        size++;
    }
    //we can remove all factors of size as if we rotate the linked by a factor of size we are going to get
    //same linked list
    k%=size;
    //edge case
    if(k==0)
        return head;
    int idx=0;
    //will be used to mark the new end of the linked list
    struct ListNode* end = head; 
    root=head;
    while(root!=NULL)
    {
        
    idx++;
    //the condition is just to find the new last node of linked list    
    if(idx==size-k)
    {
       
        end=root;
        head=root->next;
    }
    //attach end of linked list with start of linked list    
    if(root->next==NULL)
    {
        root->next=begin;
        break; 
    }
    root=root->next;
        
    }
    
    end->next=NULL;
    //head is not previous head it is our new start of linked list
    return head;
}
