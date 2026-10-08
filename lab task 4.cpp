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

void deleteEven(Node*& head)
{
    while (head != NULL && head->data % 2 == 0)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    Node* current = head;

    while (current != NULL && current->next != NULL)
    {
        if (current->next->data % 2 == 0)
        {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
        else
        {
            current = current->next;
        }
    }
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

int main()
{
    Node* head = NULL;

    insert(head, 10);
    insert(head, 15);
    insert(head, 20);
    insert(head, 25);
    insert(head, 30);
    insert(head, 35);

    cout << "Original List: ";
    display(head);

    deleteEven(head);

    cout << "\nAfter deleting even values: ";
    display(head);

    return 0;
}*/

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void josephus(int n, int m)
{
    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 1; i <= n; i++)
    {
        Node* newNode = new Node;
        newNode->data = i;

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    tail->next = head;

    Node* current = head;

    while (current->next != current)
    {
        for (int i = 1; i < m; i++)
        {
            current = current->next;
        }

        Node* temp = current->next;

        cout << "Removed: " << temp->data << endl;

        current->next = temp->next;
        delete temp;
    }

    cout << "Survivor: " << current->data << endl;

    delete current;
}

int main()
{
    int n, m;

    cout << "Enter number of people: ";
    cin >> n;

    cout << "Enter value of M: ";
    cin >> m;

    josephus(n, m);

    return 0;
}
