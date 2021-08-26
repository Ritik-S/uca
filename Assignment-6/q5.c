/*
 * Program to Remove Duplicates from Sorted List II.
 * 
 * Compilation : gcc q5.c
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


struct ListNode* deleteDuplicates(struct ListNode* head){
    //negative stores frequency of negative elements while poitive stores frequency of positive ones
    int negative[101] , positive[101];
    //initializing them with 0
    for(int i = 0; i < 101; ++i)
    {
        negative[i] = 0;
        positive[i] = 0;
    }
    //root is just to traverse the list
    struct ListNode *root =head; 
    //answer is just to attach those nodes which have frequency 1
    struct ListNode *answer=head;
    if(head==NULL)
        return head; 
    //just counting frequency of each element
    while(root!=NULL)
    {
        if(root->val>=0)
        {
            positive[root->val]++;
        }
        else
        {
            negative[-root->val]++;
        }
        
        root=root->next;
    }
    //we have assumed that 1st node has frequency 1 we will deal with it later
    root=head;
    while(root!=NULL)
    {
     
        root=root->next;
        if(root==NULL)
        break; 
        //dealing positive and negative seperately
        if(root->val>=0)
        {
            //if frequency is 1 attach with our answer node
            if(positive[root->val]==1)
            {
                answer->next=root;
                answer=answer->next;
            }
        }
        if(root->val<0)
        {
            if(negative[-root->val]==1)
            {
                answer->next=root;
                answer=answer->next;
            }
        }
    }
    //this is the end of our answer node
    answer->next=NULL;
    //We initially made an assumption that our first node's frequency is 1, time to deal with it
    while(head!=NULL)
    {    
         //moving our head node until we find a node with frequency 1
         if(head->val>=0)
         {
            
            if(positive[head->val]>1)
            {
                head=head->next;
            }
            else
            break;
         }
         else if(head->val<0)
         {
            if(negative[-head->val]>1)
            {
               head=head->next;
            }
            else
            break;
         }
    }
    return head; 
}
