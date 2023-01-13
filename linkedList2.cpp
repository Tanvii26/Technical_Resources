#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void display(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}
Node *middle(Node *head)
{
    // leap twice ek half pe reh jaega dusra pura cover kar jaega
    Node *slow = head;
    Node *fast = head;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // cout << "Middle element: " << slow->data << "\n";
    return slow;
}
Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *cNext = NULL;
    while (curr)
    {
        cNext = curr->next;
        curr->next = prev;
        prev = curr;
        curr = cNext;
    }

    return prev;
}
void create(Node* &head){
    int data;
    Node* tail = head;
    while(true){
    cout<<"Enter data: ";
    cin>>data;
    if(data == -1)
    break;
    if(head == NULL){
        head  = new Node(data);
        tail = head;
    }
    else{
    tail->next = new Node(data);   
    tail = tail->next;
    }
    }
}
int main()
{
    Node* head;
    create(head);
    display(head);
    return 0;
}