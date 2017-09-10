/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode temp;
    
    struct ListNode* final = &temp;
    
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;
    
    while(l1!=NULL && l2!=NULL)
    {
        if(l1->val >= l2->val){
            final->next = l2;
            final =l2;
            l2 = l2->next;   
        }
        else
        {
            final->next = l1;
            final = l1;
            l1 = l1->next;
        }   
    }
    if(l1!=NULL)
        final->next = l1;
    else if (l2!=NULL)
        final->next = l2;
    
    return temp.next;
}