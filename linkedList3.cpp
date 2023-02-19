// Doubly Linked List
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int n)
    {
        this->data = n;
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node() // destructor
    {
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};

int position(Node *head, int val)
{
    Node *c = head;
    int pos = 0;
    while (c)
    {
        pos++;
        if(c->data == val)
        return (pos++);
        c = c->next;
    }
    return pos;
}
void insert_begin(Node *&head, int val)
{
    Node *temp = new Node(val);
    temp->next = head;
    head->prev = temp;
    head = temp;
}
void insert_end(Node *&head, int val)
{
    Node *temp = new Node(val);
    Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = temp;
    temp->prev = p;
}
void insert_pos(Node *&head, int pos, int val)
{
    if (pos == 1)
    {
        insert_begin(head, val);
    }
    else
    {
        Node *p = head;
        Node *temp = new Node(val);
        int i = 1;
        while (i < pos - 1)
        {
            p = p->next;
            i++;
        }
        if (p->next == NULL)
        {
            insert_end(head, val);
            return;
        }
        else
        {
            temp->next = p->next;
            p->next->prev = temp;
            p->next = temp;
            temp->prev = p;
        }
    }
}
void del(Node *&head, int pos)
{
    if (pos == 1)
    {
        head->next->prev = NULL;
        head = head->next;
    }
    else
    {
        int i = 1;
        Node *p = head;
        while (i < pos)
        {
            p = p->next;
            i++;
        }
        p->prev->next = p->next;
        p->next->prev = p->prev;
        p->prev = NULL;
        p->next = NULL;
        delete p;
    }
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void printReverse(Node *head)
{
    if (head == NULL)
        return;
    printReverse(head->next);
    cout << head->data << " ";
}


void delValue(Node* head, int val){
    int pos = position(head, val);
    del(head, pos);
}
int main()
{
    Node *node1 = new Node(26);
    Node *head = node1;
    print(head);
    insert_begin(head, 15);
    print(head);
    insert_end(head, 5);
    print(head);
    insert_pos(head, 2, 3);
    print(head);
    delValue(head, 3);
    print(head);
}