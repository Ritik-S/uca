/*
 * Program for Merge Two Sorted Lists.
 * 
 * Compilation : gcc q8.c
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
//basically using recursion for combining nodes in sorted order
struct ListNode* merger(struct ListNode* list1, struct ListNode* list2)
{   //base condition
    if(list1==NULL)
        return list2; 
    else if(list2==NULL)
        return list1;
    //node with lesser value is taken as current node and then we use recursion to find the least node in rest
    //of the linked list
    if(list1->val>=list2->val)
    {
        list2->next=merger(list1,list2->next);
        return list2; 
    }
    else
    {
        list1->next=merger(list1->next,list2);
        return list1;
    }
  
}
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    //calling helper function in order to merge two lists in sorted order
    struct LisNode* merged_list=merger(l1,l2);
    //merged list is sorted and merged result of l1 and l2
    return merged_list;
}
