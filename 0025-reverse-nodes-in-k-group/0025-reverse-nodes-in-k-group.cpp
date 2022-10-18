/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
int getllsize(ListNode* head){
ListNode* temp=head;
int c=0;
while(temp!=NULL){
temp=temp->next;
c++;
}
return c;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    int n =getllsize(head);
    if(head==NULL || n < k)return head;
 ListNode *prev=NULL;
  ListNode *curr=head;
  ListNode *forw=NULL;
int c=0;
while(curr!=NULL && c!=k ){
  forw = curr -> next;
        curr -> next=prev;
        prev=curr;
        curr=forw;
    c++;
}
head->next=reverseKGroup(curr,k);



return prev;
}
};