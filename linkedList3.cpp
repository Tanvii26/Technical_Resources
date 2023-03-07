
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
    printReverse(head);
}