/*#include <iostream>
using namespace std;
int main()
{
 int start, stop;
 int sum = 0;
 cout << "Enter starting value: ";
 cin >> start;
 cout << "Enter stopping value: ";
 cin >> stop;
 for (int x = start; x <= stop; x++)
 {
 sum = sum + (x * x);
 }
 cout << "Sum of squares = " << sum << endl;
 return 0;
 
 
 ---------------------code 2---------------------------------------
 
}*/
/*#include <iostream>
using namespace std;
const int SIZE = 100;
int arrayList[SIZE];
int length = 0;
// Insert at the end
void insertAtEnd(int value)
{
 if (length == SIZE)
 {
 cout << "List is full." << endl;
 return;
 }
 arrayList[length] = value;
 length++;
 cout << "Value inserted at the end." << endl;
}
// Insert at the start
void insertAtStart(int value)
{
 if (length == SIZE)
 {
 cout << "List is full." << endl;
 return;
 }
 for (int i = length; i > 0; i--)
 {
 arrayList[i] = arrayList[i - 1];
 }
 arrayList[0] = value;
 length++;
 cout << "Value inserted at the start." << endl;
}
// Insert after a specific value
void insertAfter(int oldValue, int newValue)
{
 if (length == SIZE)
 {
 cout << "List is full." << endl;
 return;
 }
 int position = -1;
 for (int i = 0; i < length; i++)
 {
 if (arrayList[i] == oldValue)
 {
 position = i;
 break;
 }
 }
 if (position == -1)
 {
 cout << "Value not found." << endl;
 return;
 }
 for (int i = length; i > position + 1; i--)
 {
 arrayList[i] = arrayList[i - 1];
 }
 arrayList[position + 1] = newValue;
 length++;
 cout << "Value inserted after the specific value." << endl;
}
// Insert before a specific value
void insertBefore(int oldValue, int newValue)
{
 if (length == SIZE)
 {
 cout << "List is full." << endl;
 return;
 }
 int position = -1;
 for (int i = 0; i < length; i++)
 {
 if (arrayList[i] == oldValue)
 {
 position = i;
 break;
 }
 }
 if (position == -1)
 {
 cout << "Value not found." << endl;
 return;
 }
 for (int i = length; i > position; i--)
 {
 arrayList[i] = arrayList[i - 1];
 }
 arrayList[position] = newValue;
 length++;
 cout << "Value inserted before the specific value." << endl;
}
// Display the list
void displayList()
{
 if (length == 0)
 {
 cout << "List is empty." << endl;
 return;
 }
 cout << "Array List: ";
 for (int i = 0; i < length; i++)
 {
 cout << arrayList[i] << " ";
 }
 cout << endl;
}
// Delete from the end
void deleteFromEnd()
{
 if (length == 0)
 {
 cout << "List is empty." << endl;
 return;
 }
 length--;
 cout << "Value deleted from the end." << endl;
}
// Delete from the start
void deleteFromStart()
{
 if (length == 0)
 {
 cout << "List is empty." << endl;
 return;
 }
 for (int i = 0; i < length - 1; i++)
 {
 arrayList[i] = arrayList[i + 1];
 }
 length--;
 cout << "Value deleted from the start." << endl;
}
// Delete a specific value
void deleteSpecific(int value)
{
 int position = -1;
 for (int i = 0; i < length; i++)
 {
 if (arrayList[i] == value)
 {
 position = i;
 break;
 }
 }
 if (position == -1)
 {
 cout << "Value not found." << endl;
 return;
 }
 for (int i = position; i < length - 1; i++)
 {
 arrayList[i] = arrayList[i + 1];
 }
 length--;
 cout << "Specific value deleted." << endl;
}
int main()
{
 int choice;
 int value;
 int oldValue;
 int newValue;
 do
 {
 cout << "\n===== ARRAY LIST MENU =====" << endl;
 cout << "1. Insert at the end" << endl;
 cout << "2. Insert at the start" << endl;
 cout << "3. Insert after a specific value" << endl;
 cout << "4. Insert before a specific value" << endl;
 cout << "5. Display the array list" << endl;
 cout << "6. Delete from the end" << endl;
 cout << "7. Delete from the start" << endl;
 cout << "8. Delete a specific value" << endl;
 cout << "9. Exit" << endl;
 cout << "Enter your choice: ";
 cin >> choice;
 switch (choice)
 {
 case 1:
 cout << "Enter value: ";
 cin >> value;
 insertAtEnd(value);
 break;
 case 2:
 cout << "Enter value: ";
 cin >> value;
 insertAtStart(value);
 break;
 case 3:
 cout << "Enter the existing value: ";
 cin >> oldValue;
 cout << "Enter the new value: ";
 cin >> newValue;
 insertAfter(oldValue, newValue);
 break;
 case 4:
 cout << "Enter the existing value: ";
 cin >> oldValue;
 cout << "Enter the new value: ";
 cin >> newValue;
 insertBefore(oldValue, newValue);
 break;
 case 5:
 displayList();
 break;
 case 6:
 deleteFromEnd();
 break;
 case 7:
 deleteFromStart();
 break;
 case 8:
 cout << "Enter the value to delete: ";
 cin >> value;
 deleteSpecific(value);
 break;
 case 9:
 cout << "Program ended." << endl;
 break;
 default:
 cout << "Invalid choice." << endl;
 }
 } while (choice != 9);
 return 0;
}*/


/////-------------------- code 3---------------------------------------------


#include <iostream>
using namespace std;
int main()
{
 int arrayList[100];
 int length;
 int searchValue;
 cout << "Enter the number of values: ";
 cin >> length;
 cout << "Enter the values:" << endl;
 for (int i = 0; i < length; i++)
 {
 cin >> arrayList[i];
 }
 cout << "Enter the value to search: ";
 cin >> searchValue;
 int index = 0;
 bool found = false;
 while (index < length)
 {
 if (arrayList[index] == searchValue)
 {
 found = true;
 break;
 }
 index++;
 }
 if (found == true)
 {
 cout << "Value found at position "
 << index + 1 << endl;
 }
 else
 {
 cout << "Value not found." << endl;
 }
 return 0;
}

