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
Node *head1, *head2, *head3;

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
void create(Node *&head)
{
    int data;
    Node *tail = head;
    while (true)
    {
        cout << "Enter data: ";
        cin >> data;
        if (data == -1)
        {
            break;
        }
        if (head == NULL)
        {
            head = new Node(data);
            tail = head;
        }
        else
        {
            tail->next = new Node(data);
            tail = tail->next;
        }
    }
}
Node *mergeTwo(Node *l1, Node *l2)
{
    Node *ans = new Node();
    Node *p = ans;
    while (l1 && l2)
    {

        if (l1->data < l2->data)
        {
            p->next = l1;
            l1 = l1->next;
        }
        else
        {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    p->next = (l1 != NULL) ? l1 : l2;
    return ans->next;
}
Node *mergeKLists(vector<Node *> lists)
{
    if (lists.size() == 0)
        return NULL;
    if (lists.size() == 1)
        return lists[0];
    int size = lists.size();
    int last = size - 1;
    while (last != 0)
    {
        int i = 0, j = last;
        while (i < j)
        {
            lists[i] = mergeTwo(lists[i], lists[j]);
            i++, j--;
            if (i >= j)
            {
                last = j;
            }
        }
    }
    return lists[0];
}

Node *mergeSort(Node *head)
{
    if (!head || !head->next)
        return head;
    Node *mid = middle(head);
    Node *partTwo = mid->next;
    mid->next = NULL;

    Node *p1 = mergeSort(head);
    Node *p2 = mergeSort(partTwo);

    return mergeTwo(p1, p2);
}

int main()
{
    create(head1);
    Node *ans;
    /*create(head2);
    create(head3);
    vector<Node*> list;
    list.push_back(head1);
    list.push_back(head2);
    list.push_back(head3);
    ans = mergeKLists(list);
    cout<<"Merging k lists";
    display(ans);*/

    cout << "Merge Sort";
    if (!head1 || !head1->next)
        display(head1);
    else
    {
        mergeSort(head1);
    }
    return 0;
}