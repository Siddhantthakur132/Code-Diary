class Solution {
  public:
    Node* reverseList(struct Node* head) {
        // code here
        Node* curr=head;
        Node* prev=NULL,*fut=NULL;
        
        while(curr)
        {
            fut=curr->next;
            curr->next=prev;
            prev=curr;
            curr=fut;
        }
        
        return prev;
    }
};