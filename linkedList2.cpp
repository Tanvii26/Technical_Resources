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

Node *evenOdd(Node *head)
{
    if (!head || !head->next)
        return head;
    Node *even = new Node();
    Node *odd = new Node();
    Node *evenInsert = even;
    Node *oddInsert = odd;
    Node *c = head;
    while (c)
    {
        if (c->data % 2 == 0)
        {
            evenInsert->next = c;
            evenInsert = evenInsert->next;
        }
        else
        {
            oddInsert->next = c;
            oddInsert = oddInsert->next;
        }
        c = c->next;
    }
    evenInsert->next = odd->next;
    return even->next;
}

Node *reverseKGroup(Node *head, int k)
{
    if (!head || k == 1)
        return head;
    int count = 0;
    Node *p = head;
    while (p)
    {
        count++;
        p = p->next;
    }
    Node *dummy = new Node(-1);
    dummy->next = head;
    Node *prev = dummy, *curr = dummy, *cNext = dummy;
    while (count >= k)
    {
        curr = prev->next;
        cNext = curr->next;
        for (int i = 1; i < k; i++)
        {
            curr->next = cNext->next;
            cNext->next = prev->next;
            prev->next = cNext;
            cNext = curr->next;
        }
        prev = curr;
        count -= k;
    }
    return dummy->next;
}

Node *getIntersectionNode(Node *headA, Node *headB)
{
    if (!headA || !headB)
        return NULL;
    Node *p1 = headA;
    Node *p2 = headB;
    while (p1 != p2)
    {
        if (p1 == NULL)
        {
            p1 = headB;
        }
        else
        {
            p1 = p1->next;
        }
        if (p2 == NULL)
        {
            p2 = headA;
        }
        else
        {
            p2 = p2->next;
        }
    }
    return p1;
}

Node *addTwoNumbers(Node *l1, Node *l2)
{
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    l1 = reverse(l1);
    l2 = reverse(l2);
    Node *p1 = l1;
    Node *p2 = l2;
    Node *ans = new Node(-1);
    Node *p = ans;
    int sum = 0, carry = 0;
    while (p1 && p2)
    {
        sum = p1->data + p2->data + carry;
        carry = sum / 10;
        sum = sum % 10;
        p->next = new Node(sum);
        p1 = p1->next;
        p2 = p2->next;
        p = p->next;
    }
    while (p1)
    {
        sum = p1->data + carry;
        carry = sum / 10;
        sum = sum % 10;
        p->next = new Node(sum);
        p1 = p1->next;
        p = p->next;
    }

    while (p2)
    {
        sum = p2->data + carry;
        carry = sum / 10;
        sum = sum % 10;
        p->next = new Node(sum);
        p2 = p2->next;
        p = p->next;
    }
    if (carry != 0)
    {
        p->next = new Node(carry);
    }
    ans = ans->next;
    ans = reverse(ans);
    return ans;
}

Node *subtractTwoNumbers(Node *l1, Node *l2)
{
    if (l2 == NULL)
        return l1;
    if (l1 == NULL)
    {
        l2->data = -(l2->data);
        return l2;
    }
    l1 = reverse(l1);
    l2 = reverse(l2);
    Node *p1 = l1;
    Node *p2 = l2;
    Node *ans = new Node(-1);
    Node *p = ans;
    int val = 0, borrow = 0;
    while (p1)
    {
        val = borrow + p1->data - (p2 != NULL ? p2->data : 0);
        if (val < 0)
        {
            val += 10;
            borrow = -1;
        }
        else
        {
            borrow = 0;
        }
        p->next = new Node(val);
        p = p->next;
        p1 = p1->next;
        if (p2)
        {
            p2 = p2->next;
        }
    }
    return reverse(ans->next);
}

Node *multiplyWithDigit(Node *head, int digit)
{
    Node *ans = new Node(-1);
    Node *p = ans;
    Node *curr = head;
    int carry = 0;
    while (curr || carry != 0)
    {
        int sum = carry + (curr != NULL ? curr->data : 0) * digit;
        carry = sum / 10;
        int val = sum % 10;

        p->next = new Node(val);
        p = p->next;
        if (curr)
            curr = curr->next;
    }
    return ans->next;
}
void addToMultiply(Node *prod, Node* &ansPtr)
{
    Node *p1 = prod;
    Node *p2 = ansPtr;
    int carry = 0;
    while (p1 || carry != 0)
    {
        int sum = carry + (p1? p1->data: 0) +(p2->next? p2->next->data : 0);

        carry = sum/10;
        int val = sum%10;


        if(p2->next)
        p2->next->data = val;
        else
        p2->next = new Node(val);

        p2 = p2->next;
        if(p1) p1 = p1->next;
    }

}
Node *multiplyTwoLL(Node *l1, Node *l2)
{
    l1 = reverse(l1);
    l2 = reverse(l2);
    Node *ans = new Node(-1);
    Node *ansPtr = ans;
    Node *l2Ptr = l2;
    while (l2Ptr)
    {
        Node *prod = multiplyWithDigit(l1, l2Ptr->data);
        addToMultiply(prod, ansPtr);
        ansPtr = ansPtr->next;
        l2Ptr = l2Ptr->next;
    }
    return reverse(ans->next);
}

Node *deleteDuplicates(Node *p)
{
    Node *head = p;
    while (head && head->next)
    {
        if (head->data == head->next->data)
        {
            Node *pNext = head->next;
            head->next = head->next->next;
            pNext->next = NULL;
        }
        else
        {
            head = head->next;
        }
    }
    return p;
}

Node *deleteAllDuplicates(Node *head)
{
    if (!head || !head->next)
        return head;
    Node *ans = new Node(-1);
    Node *prev = ans;
    prev->next = head;
    Node *p = head->next;
    while (p)
    {
        bool dupFound = false;
        while (p && prev->next->data == p->data)
        {
            dupFound = true;
            p = p->next;
        }
        if (dupFound)
            prev->next = p;
        else
        {
            prev = prev->next;
        }
        if (p)
            p = p->next;
    }
    return ans->next;
}

Node *segregate(Node *head)
{
    if (!head || !head->next)
        return head;
    Node *zero = new Node(-1);
    Node *pZero = zero;
    Node *one = new Node(-1);
    Node *pOne = one;
    Node *two = new Node(-1);
    Node *pTwo = two;
    Node *p = head;
    while (p)
    {
        if (p->data == 0)
        {
            pZero->next = p;
            pZero = pZero->next;
        }
        else if (p->data == 1)
        {
            pOne->next = p;
            pOne = pOne->next;
        }
        else
        {
            pTwo->next = p;
            pTwo = pTwo->next;
        }
        p = p->next;
    }
    pZero->next = one->next;
    pOne->next = two->next;
    pTwo->next = NULL;
    return zero->next;
}


vector<Node*> pivotPartition(Node* head, int pvtIdx){
    Node* small = new Node(-1); // holds values smaller than pivot value
    Node* large = new Node(-1); // holds values larger than pivot value
    Node* p = head, *sPtr = small, *lPtr = large, *pivot = head;


    while(pvtIdx-- >0){
        pivot = pivot->next;
    }
    while (p)
    {   //only in case of non pivot value else skip for pivot
        if(p!= pivot){
            if(p->data <= pivot->data){
                sPtr->next = p;
                sPtr = sPtr->next;
            }
            else{
                lPtr->next = p;
                lPtr = lPtr->next;
            }
        }
        p = p->next;
    }

    sPtr->next = NULL;
    pivot->next = NULL;
    lPtr->next = NULL;

    vector<Node*> v;
    v.push_back(small->next);
    v.push_back( pivot);
    v.push_back(large->next);

    return v;
    
}

int size(Node* head){
    if(!head) return 0;
    Node* p = head;
    int len =0;
    while(p){
        len++;
        p=p->next;
    }
    return len;
}

vector<Node*> mergeWithPivot(vector<Node*> left, Node* pvt, vector<Node*> right){
    Node* head = NULL, *tail=NULL;

    //when both part exist
    if(left[0] && right[0]){
        left[1]->next = pvt;
        pvt->next = right[0];
        head = left[0];
        tail = right[1];
    }
    else if (left[0])
    {
        left[1]->next = pvt;
        head = left[0];
        tail = pvt;
    }
    else if (right[0])
    {
        pvt->next = right[0];
        head = pvt;
        tail = right[1];
    }
    else{
        head = pvt;
        tail = pvt;
    }
    vector<Node*> v;
    v.push_back(head);
    v.push_back(tail);
    return v;
}
vector<Node*> quickSortHelper(Node* head){
    vector<Node*> ans;
    if(!head || !head->next){
        ans.push_back(head);
        ans.push_back(head);
        return ans;
        //head & tail of merged list as vector
    }


    int len = size(head);
    int pvtIdx = len/2;

    vector<Node*> subPartsArray = pivotPartition(head,pvtIdx);

    vector<Node*> leftSorted = quickSortHelper(subPartsArray[0]);
    vector<Node*> rightSorted = quickSortHelper(subPartsArray[2]);

    return mergeWithPivot(leftSorted, subPartsArray[1], rightSorted);

}

Node* quickSort(Node* head){
    return quickSortHelper(head)[0];
}
int main()
{
    create(head1);
    Node *ans;
    /* cout<<"Merge K Sorted Lists\n";
    create(head2);
    create(head3);
    vector<Node*> list;
    list.push_back(head1);
    list.push_back(head2);
    list.push_back(head3);
    ans = mergeKLists(list);
    cout<<"Merging k lists";
    display(ans);*/

    /*cout << "Merge Sort\n";
        ans = mergeSort(head1);
        display(ans);*/

    /*cout<<"Even followed by odd\n";
    ans = evenOdd(head1);
    display(ans);*/

    /*cout<<"Reverse in K groups";
    ans = reverseKGroup(head1, 3);
    display(ans);*/

    /*cout<<"Addidtion\n";
    ans = addTwoNumbers(head1, head2);
    display(ans);*/

    /*cout<<"Subtraction\n";
    ans = subtractTwoNumbers(head1, head2);
    display(ans);*/

    /*ans = multiplyTwoLL(head1,head2);
    display(ans);*/

    ans = quickSort(head1);
    display(ans);

    return 0;
}