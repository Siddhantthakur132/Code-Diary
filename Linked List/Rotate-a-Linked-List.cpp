class Solution {
  public:
    Node* rotate(Node* head, int k) {
        // Your code here
        Node* temp=head;
        int cnt=0;
        
        if(head==NULL || head->next==NULL)
        return head;
        
        while(temp)
        {
            cnt++;
            temp=temp->next;
        }
        
        k=k%cnt;
        
        if(k==0)
        return head;
        
     
        Node* curr=head;
        Node* prev=NULL;
        
        while(k--)
        {
            prev=curr;
            curr=curr->next;
        }
        
        prev->next=NULL;
        Node*tail=curr;
        
        while(tail->next!=NULL)
        {
            tail=tail->next;
        }
        
        tail->next=head;
        head=curr;
        return head;
    }
};