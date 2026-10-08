////Lab Task 1 — Balanced Brackets Using Stack

/*#include <iostream>
#include <string>
using namespace std;

struct Node
{
    char data;
    Node* next;
};

void push(Node*& top, char value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

char pop(Node*& top)
{
    char value = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return value;
}

bool isMatching(char open, char close)
{
    if (open == '(' && close == ')')
        return true;

    if (open == '{' && close == '}')
        return true;

    if (open == '[' && close == ']')
        return true;

    return false;
}

bool isBalanced(string expression)
{
    Node* top = NULL;

    for (int i = 0; i < expression.length(); i++)
    {
        char ch = expression[i];

        if (ch == '(' || ch == '{' || ch == '[')
        {
            push(top, ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (top == NULL)
                return false;

            char open = pop(top);

            if (!isMatching(open, ch))
                return false;
        }
    }

    return top == NULL;
}

int main()
{
    string expression;

    cout << "Enter brackets: ";
    cin >> expression;

    if (isBalanced(expression))
        cout << "Balanced";
    else
        cout << "Not Balanced";

    return 0;
}*/

//////Lab Task 2 — Infix to Postfix Using Dynamic Stack


/*#include <iostream>
#include <string>
using namespace std;

struct Node
{
    char data;
    Node* next;
};

void push(Node*& top, char value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

char pop(Node*& top)
{
    char value = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return value;
}

char peek(Node* top)
{
    return top->data;
}

int precedence(char op)
{
    if (op == '^')
        return 3;

    if (op == '*' || op == '/')
        return 2;

    if (op == '+' || op == '-')
        return 1;

    return 0;
}

bool isOperator(char ch)
{
    return ch == '+' || ch == '-' ||
           ch == '*' || ch == '/' || ch == '^';
}

string infixToPostfix(string infix)
{
    Node* top = NULL;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        if (ch == ' ')
            continue;

        if ((ch >= 'A' && ch <= 'Z') ||
            (ch >= 'a' && ch <= 'z') ||
            (ch >= '0' && ch <= '9'))
        {
            postfix += ch;
        }
        else if (ch == '(')
        {
            push(top, ch);
        }
        else if (ch == ')')
        {
            while (top != NULL && peek(top) != '(')
            {
                postfix += pop(top);
            }

            if (top != NULL)
                pop(top);
        }
        else if (isOperator(ch))
        {
            while (top != NULL &&
                   peek(top) != '(' &&
                   precedence(peek(top)) >= precedence(ch))
            {
                postfix += pop(top);
            }

            push(top, ch);
        }
    }

    while (top != NULL)
    {
        postfix += pop(top);
    }

    return postfix;
}

int main()
{
    string infix;

    cout << "Enter infix expression: ";
    cin >> infix;

    cout << "Postfix expression: "
         << infixToPostfix(infix);

    return 0;
}*/


////Lab Task 3 — Evaluate Postfix Expression Using Dynamic Stack

#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void push(Node*& top, int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int pop(Node*& top)
{
    int value = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return value;
}

int getValue(char variable)
{
    int value;

    cout << "Enter value of " << variable << ": ";
    cin >> value;

    return value;
}

int calculate(int a, int b, char op)
{
    if (op == '+')
        return a + b;

    if (op == '-')
        return a - b;

    if (op == '*')
        return a * b;

    if (op == '/')
        return a / b;

    return 0;
}

int evaluatePostfix(string postfix)
{
    Node* top = NULL;

    for (int i = 0; i < postfix.length(); i++)
    {
        char ch = postfix[i];

        if (ch >= 'A' && ch <= 'Z')
        {
            int value = getValue(ch);
            push(top, value);
        }
        else
        {
            int b = pop(top);
            int a = pop(top);

            int result = calculate(a, b, ch);

            push(top, result);
        }
    }

    return pop(top);
}

int main()
{
    string postfix;

    cout << "Enter postfix expression: ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);

    cout << "Result: " << result;

    return 0;
}
