Node* reverse(Node* curr,Node*prev)
{
    if(curr==NULL)
    return prev;
    
    Node* fut=curr->next;
    curr->next=prev;
    
    return reverse(fut,curr);
}
Node* skipLeadingZeros(Node* head) {
    while (head && head->data == 0 && head->next) {
        head = head->next;
    }
    return head;
}

class Solution {
  public:
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        
        Node* first = reverse(skipLeadingZeros(num1), NULL);
        Node* sec = reverse(skipLeadingZeros(num2), NULL);
        int carry=0;
        int sum;
        Node* curr1=first;
        Node* curr2=sec;
        
        Node* head=new Node(-1);
        Node* tail=head;
        
        while(curr1 && curr2)
        {
            sum = 0;
            sum=curr1->data+curr2->data+carry;
            
            tail->next=new Node(sum%10);
            curr1=curr1->next;
            curr2=curr2->next;
            
            tail=tail->next;
            carry=sum/10;
        }
        
        while(curr1)
        {
             sum = 0;
            sum=curr1->data+carry;
            tail->next=new Node(sum%10);
            curr1=curr1->next;
            tail=tail->next;
            carry=sum/10;
        }
            
        while(curr2)
        {
     
             sum = 0;
            sum=curr2->data+carry;
            tail->next=new Node(sum%10);
            curr2=curr2->next;
            tail=tail->next;
            carry=sum/10;
        }
        while(carry)
        {
          
            tail->next=new Node(carry%10);
            carry=carry/10;
            tail=tail->next;
        }
        
        return reverse(head->next,NULL);
       
        
    }
};