#include <stdio.h>
#include <stdlib.h>
// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};
 

int getlength(struct ListNode* l){
    struct ListNode *p = l;
    int length = 0;
    
    while(p!=NULL)
    {
        p=p->next;
        length++;
    }
    return length;
}

struct ListNode *newNode(int data)
{
    struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
    new_node->val = data;
    new_node->next = NULL;
    return new_node;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    struct ListNode *final =NULL;
    struct ListNode *prev, *temp = NULL;
    int add = 0;
    
    while(l1 != NULL || l2 != NULL)
    {
        int curSum = (l1?l1->val:0) + (l2?l2->val:0) +add;
        if(curSum >=10)
        {
            curSum = curSum - 10;
            add = 1;
        }
        else 
        {
            add = 0;
        }
        
        temp = newNode(curSum);
        
        if(final == NULL)
            final = temp;
        else
            prev->next = temp;
        
        prev = temp;
        
        if(l1)l1 = l1->next;
        if(l2)l2 = l2->next;
    }
    if(add>=1)
        temp->next = newNode(add);
    
    return final;
}
/////////////////below are main functions/////////////////////

void push(struct ListNode** head_ref, int new_data)
{
    struct ListNode* new_node = newNode(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// A utility function to print a linked list
void printList(struct ListNode *node)
{
    while(node != NULL)
    {
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n");
}
 
/* Driver program to test above function */
int main(void)
{
    struct ListNode* res = NULL;
    struct ListNode* first = NULL;
    struct ListNode* second = NULL;
 
    // create first list 7->5->9->4->6
    push(&first, 6);
    push(&first, 4);
    push(&first, 9);
    push(&first, 5);
    push(&first, 7);
    printf("First List is ");
    printList(first);
 
    // create second list 8->4
    push(&second, 4);
    push(&second, 8);
    printf("Second List is ");
    printList(second);
 
    // Add the two lists and see result
    res = addTwoNumbers(first, second);
    printf("Resultant list is ");
    printList(res);
 
   return 0;
}