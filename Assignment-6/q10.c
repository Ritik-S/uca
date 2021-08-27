/*
 * Program to implement Linked List Cycle II
 * 
 * Compilation : gcc q10.c
 * Execution : ./a.out
 *
 * @Ritik Sedana , (1910990138) , 23/08/21 .
 * Assignment_6
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
        struct ListNode * turtle, *hair;
        if(head == NULL)
            return false;
        if(head -> next==NULL)
            return false;
        //slow pointer
        turtle = head;
        //fast pointer
        hair = head; 
       
        while(hair!=NULL&&hair->next!=NULL)
        {
            hair = hair -> next -> next;
            turtle = turtle -> next;
            if(turtle==hair)
            {
             turtle = head;
             //cycle is detected so we will be finding the node where cycle begins 
	     while(turtle != hair)
             {
	         turtle = turtle -> next;
		 hair = hair -> next;
	     }
	        return turtle;
            }
        }
        return NULL;
}
