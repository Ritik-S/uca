/*
 * Program for Remove Nth Node From End of List.
 * 
 * Compilation : gcc q6.c
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


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* root = head; 
    //size is the total size of linked list
    int size=0;
    while(root!=NULL)
    {
        root=root->next;
        size++;
    }
    //root is just to traverse the linked list
    root=head; 
    int idx=0;
    while(root!=NULL)
    {
        idx++;
        //if it is the node just behind the node which is to be removed then we set the next pointer accordingly
        if(idx==(size-n))
        {
            //if next to next node is NULL 
            if(size-n==size-1)
                root->next=NULL;
            //else point toward next to next node
            else
                root->next=root->next->next;
        }
        root=root->next; 
    }
    //handling special case when we are to remove 1st node because there was no node behind it so it became edge case
    //for this apporach
    if(size==n)
    {
        head=head->next;
    }
    return head;
}
