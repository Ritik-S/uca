/*
 * Program for Reverse Linked List II.
 * 
 * Compilation : gcc q7.c
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


struct ListNode* reverseBetween(struct ListNode* head, int left, int right){

    //root is to traverse ,lt points towards the node which is 1 postion left of left and right points towards right node , pre cur nxt are used 
    //because we are changing pointer while we are moving so these three pointers will help in moving
    struct ListNode *root = head ,*lt,*rt,*pre,*cur,*nxt; 
    if(head == NULL)
        return head;
    if(head -> next == NULL)
        return head;
    //there was edge case when left is 1 so there was no node behind 1st node 
    long long i = 0,handled = 0;
    //if handled = 1 means edge case was there else there was no edge case 
    struct ListNode* extra = (struct ListNode*) malloc (sizeof (struct ListNode));
    if(left == 1)
    {
        //In case of edge case we insert 1 more node at the begining just to avoid any runtime error so head also changed 
        handled = 1; 
        extra -> next = head;
        extra -> val = 0;
        head = extra;
        //now due to extra node left will never be 1 so it will be solved automatically by program
        left++;
        right++;
    }
    pre = NULL;
    cur = head; 
    nxt = head->next;
    lt = head;
    rt = head;
    
    while(cur != NULL)
    {
       ++i;
       if(i == left-1)
          lt = cur;
       // Simply reversing the node if it lies between left+1 and right
       if(i > left && i <= right)
       {
          cur -> next = pre;
       }
       if(i == right)
       {
          //now we change pointers of 1 node behind left position node and also of right position node
          lt -> next -> next = nxt;
          lt -> next = cur;  
            
       }  
        
       pre = cur; 
       cur = nxt;
       if(nxt != NULL)
          nxt = cur -> next;
    }

   //if handled means there was edge case and we added one node behind our head node so we make head as it was previously
   if(handled)
   {
       head=head -> next;
   }
   return head; 
}
