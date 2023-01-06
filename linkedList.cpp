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
void display(Node *&head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}
void insert_begin(Node *&head, Node *&tail, int val)
{
    Node *temp = new Node(val);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}
void insert_end(Node *&head, Node *&tail, int val)
{
    Node *temp = new Node(val);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}
void insert_pos(Node *&head, Node *&tail, int val, int pos)
{
    if (pos == 0)
    {
        insert_begin(head, tail, val);
    }

    else if (pos < 0)
    {
        cout << "Invalid index \n";
    }
    else
    {
        Node *temp = new Node(val);
        Node *t = head;
        for (int i = 1; i < pos; i++)
        {
            t = t->next;
        }
        temp->next = t->next;
        t->next = temp;
    }
}
void remove_begin(Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout << "List is empty \n";
    }
    else if (head->next == NULL)
    {
        head = tail = NULL;
    }
    else
    {
        Node *temp = head;
        head = head->next;
        delete (temp);
    }
}
void addLast(Node *&head, int data)
{
    if (head == NULL)
    {
        head = new Node(data);
    }
    else
    {
        Node *p = head;
        while (p->next)
        {
            p = p->next;
        }
        p->next = new Node(data);
    }
}
void remove_end(Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout << "List is empty \n";
    }
    else if (head->next == NULL)
    {
        head = tail = NULL;
    }
    else
    {
        Node *temp = head;
        while (temp->next->next)
        {
            temp = temp->next;
        }
        tail = temp;
        tail->next = NULL;
    }
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
void kthFromEnd(Node *&head, Node *&tail, int k)
{
    // Using Single Loop
    // Slow & Fast pointer wala concept
    // Jab tak fast tail tak jaega, slow k times peeche reh jaega which is Kth from end :)🍥
    Node *slow = head;
    Node *fast = head;
    for (int i = 1; i < k; i++)
    {
        fast = fast->next;
    }
    while (fast != tail)
    {
        slow = slow->next;
        fast = fast->next;
    }
    cout << k << "th element from end: " << slow->data << "\n";
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

Node *mergeTwo(Node *p1, Node *p2)
{
    Node *p = NULL;
    if (p1->data <= p2->data)
    {
        p = p1;
        p1 = p1->next;
    }
    else
    {
        p = p2;
        p2 = p2->next;
    }
    Node *pTail = p;
    while (p1 && p2)
    {
        Node *temp = NULL;
        if (p1->data <= p2->data)
        {
            temp = p1;
            p1 = p1->next;
        }
        else
        {
            temp = p2;
            p2 = p2->next;
        }
        pTail->next = temp;
        pTail = temp;
    }
    if (p1)
    {
        pTail->next = p1;
    }
    else if (p2)
    {
        pTail->next = p2;
    }

    return p;
}

Node *mergeSort(Node *head, Node *tail)
{
    if (head == tail)
    {
        Node *temp = NULL;
        addLast(temp, head->data);
        return temp;
    }
    Node *mid = middle(head);
    Node *first = mergeSort(head, mid);
    Node *second = mergeSort(mid->next, tail);
    Node *ans = mergeTwo(first, second);
    return ans;
}

void kReverse(Node *&head, Node *&tail, int k)
{
    Node *prev, *ptail;
    while (head)
    {
        Node *curr, *ctail;
        for (int i = 0; i < k; i++)
        {
            int data = head->data;
            remove_begin(head, tail);
            insert_begin(curr, ctail, data);
        }
        if (!prev)
        {
            prev = curr;
            ptail = ctail;
            // prev ki tail gets updated
        }
        else
        {
            ptail->next = curr;
            ptail = ctail;
        }
    }
}

bool isPalindrome(Node *head)
{
    if (!head || !head->next)
    {
        return true;
    }
    Node *mid = middle(head);
    Node *temp = mid->next;
    mid->next = NULL;
    temp = reverse(temp);
    Node *p1 = head;
    Node *p2 = temp;
    while (p2)
    {
        if (p1->data != p2->data)
        {
            return false;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    temp = reverse(temp);
    mid->next = temp;
    return true;
}

Node *foldList(Node *head)
{
    Node *p1 = head;
    Node *p2 = middle(head);

    Node *rev = reverse(p2);
    Node *ans = new Node();
    Node *p = ans;
    while (p1 || p2)
    {
        if (p1)
        {
            p->next = p1;
            p = p->next;
            p1 = p1->next;
        }
        if (p2)
        {
            p->next = p2;
            p = p->next;
            p2 = p2->next;
        }
    }
    return head->next;
}

Node *addTwo(Node *head1, Node *head2)
{
    Node *first = reverse(head1);
    Node *second = reverse(head2);
    int carry = 0;
    Node *sum;
    while (first || second || carry == 1)
    {
        int val = 0;
        if (first)
        {
            val += first->data + carry;
        }
        if (second)
        {
            val += first->data + carry;
        }
        carry = val / 10;
        val = val % 10;
        Node *temp = new Node(val);
        temp->next = sum;
        sum = temp;
        if (first)
            first = first->next;
        if (second)
            second = second->next;
    }
    return sum;
}

Node* intersectionPoint(Node* head1, Node*head2){
if(!head1 || !head2)
return NULL;
Node * p1 = head1;
Node * p2 = head2;
while(p1 != p2){
    if(p1 == NULL){
        p1= p2;
    }
    else 
    {
        p1 = p1->next;
    }
    if(p2 == NULL){
        p2= p1;
    }
    else 
    {
        p2 = p2->next;
    }
}
return p1;
}
int main()
{
    Node *head1, *tail1, *head2, *tail2;
    insert_begin(head1, tail1, 5);
    insert_begin(head1, tail1, 4);
    insert_begin(head1, tail1, 0);
    insert_end(head1, tail1, 6);
    insert_pos(head1, tail1, 3, 1);
    display(head1);
    insert_begin(head2, tail2, 4);
    insert_begin(head2, tail2, 8);
    insert_begin(head2, tail2, 7);
    insert_begin(head2, tail2, 6);
    insert_begin(head2, tail2, 9);
    insert_begin(head2, tail2, 0);
    display(head2);
    Node * intersect = intersectionPoint(head1,head2);
    cout<< "Intersection Point: "<<intersect->data;
    return 0;
}
