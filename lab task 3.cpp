/*#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void insert(Node*& head, int value)
{
    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Reverse using loop
void reverseUsingLoop(Node* head)
{
    int arr[100];
    int count = 0;

    Node* temp = head;

    while (temp != NULL)
    {
        arr[count] = temp->data;
        count++;
        temp = temp->next;
    }

    for (int i = count - 1; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }
}

// Reverse using recursion
void reverseUsingRecursion(Node* head)
{
    if (head == NULL)
    {
        return;
    }

    reverseUsingRecursion(head->next);

    cout << head->data << " ";
}

int main()
{
    Node* head = NULL;

    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);

    cout << "Reverse using Loop: ";
    reverseUsingLoop(head);

    cout << "\nReverse using Recursion: ";
    reverseUsingRecursion(head);

    return 0;
}*/
/*#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void insert(Node*& head, int value)
{
    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void display(Node* head)
{
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node* mergeLists(Node* head1, Node* head2)
{
    Node* newHead = NULL;

    Node* temp = head1;

    while (temp != NULL)
    {
        insert(newHead, temp->data);
        temp = temp->next;
    }

    temp = head2;

    while (temp != NULL)
    {
        insert(newHead, temp->data);
        temp = temp->next;
    }

    return newHead;
}

int main()
{
    Node* head1 = NULL;
    Node* head2 = NULL;

    insert(head1, 10);
    insert(head1, 20);
    insert(head1, 30);

    insert(head2, 40);
    insert(head2, 50);
    insert(head2, 60);

    cout << "First List: ";
    display(head1);

    cout << "\nSecond List: ";
    display(head2);

    Node* head3 = mergeLists(head1, head2);

    cout << "\nMerged Third List: ";
    display(head3);

    return 0;
}*/
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void insert(Node*& head, int value)
{
    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void display(Node* head)
{
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void findOccurrences(Node* head, int value)
{
    Node* temp = head;
    int position = 1;
    int count = 0;

    while (temp != NULL)
    {
        if (temp->data == value)
        {
            cout << value << " found at position "
                 << position << endl;

            count++;
        }

        temp = temp->next;
        position++;
    }

    if (count == 0)
    {
        cout << value << " not found in the list." << endl;
    }
    else
    {
        cout << "Total occurrences: " << count << endl;
    }
}

int main()
{
    Node* head = NULL;

    insert(head, 10);
    insert(head, 20);
    insert(head, 10);
    insert(head, 30);
    insert(head, 10);
    insert(head, 40);

    cout << "Linked List: ";
    display(head);

    int value;

    cout << "\nEnter value to search: ";
    cin >> value;

    findOccurrences(head, value);

    return 0;
}
