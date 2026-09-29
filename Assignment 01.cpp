#include <iostream>
using namespace std;
const int CAPACITY = 20;
struct ArrayList
{
 int data[CAPACITY];
 int size = 0;
};
// value ko end mein add karta hai
bool insertEnd(ArrayList &list, int value)
{
 if (list.size >= CAPACITY)
 return false;
 list.data[list.size] = value;
 list.size = list.size + 1;
 return true;
}
// value ko start mein add karta hai, baqi sab ko ek jagah shift karta hai
bool insertAtBeginning(ArrayList &list, int value)
{
 if (list.size >= CAPACITY)
 return false;
 for (int i = list.size; i > 0; i--)
 {
 list.data[i] = list.data[i - 1];
 }
 list.data[0] = value;
 list.size = list.size + 1;
 return true;
}
// position wali value delete karta hai, aage wali values peeche shift ho jati hain
bool deleteAtPosition(ArrayList &list, int position)
{
 if (position < 0 || position >= list.size)
 return false;
 for (int i = position; i < list.size - 1; i++)
 {
 list.data[i] = list.data[i + 1];
 }
 list.size = list.size - 1;
 return true;
}
// pura list print karta hai
void displayList(const ArrayList &list)
{
 for (int i = 0; i < list.size; i++)
 {
 cout << list.data[i] << " ";
 }
 cout << endl;
}
// simple abs function, taake ternary na likhni pare
double absValue(double x)
{
 if (x < 0)
 return -x;
 return x;
}
int main()
{
 ArrayList list;
 // ====== APNI REGISTRATION NUMBER KE LAST 2 DIGITS YAHAN DAALEIN ======
 int your_reg_no = 8; // example: reg no ...045 hai to 45 likhna
 // ---------- Part A: List banana ----------
 insertEnd(list, 18);
 insertEnd(list, 7);
 insertEnd(list, 45);
 insertEnd(list, 11);
 insertEnd(list, 36);
 insertEnd(list, your_reg_no);
 insertEnd(list, 21);
 insertEnd(list, 13);
 insertEnd(list, 29);
 cout << "Initial ArrayList: ";
 displayList(list);
 // ---------- Part B: ptr se traverse, sum, min, max ----------
 int *ptr = list.data;
 int *minPtr = list.data;
 int *maxPtr = list.data;
 int sum = 0;
 for (int i = 0; i < list.size; i++)
 {
 ptr = &list.data[i]; // ptr ko current element ka address do
 sum = sum + *ptr;
 if (*ptr < *minPtr)
 minPtr = ptr;
 if (*ptr > *maxPtr)
 maxPtr = ptr;
 }
 cout << "Minimum Value: " << *minPtr << endl;
 cout << "Maximum Value: " << *maxPtr << endl;
 cout << "Sum: " << sum << endl;
 // ---------- Part C: Median ----------
 int temp[CAPACITY];
 for (int i = 0; i < list.size; i++)
 {
 temp[i] = list.data[i]; // temp array mein copy kiya, original nahi chheda
 }
 // simple bubble sort (apna banaya hua, sort() use nahi kiya)
 for (int i = 0; i < list.size - 1; i++)
 {
 for (int j = 0; j < list.size - 1 - i; j++)
 {
 if (temp[j] > temp[j + 1])
 {
 int swapTemp = temp[j];
 temp[j] = temp[j + 1];
 temp[j + 1] = swapTemp;
 }
 }
 }
 int medianValue = temp[list.size / 2]; // 9 values -> middle index 4
 int *medianPtr = list.data;
 for (int i = 0; i < list.size; i++)
 {
 if (list.data[i] == medianValue)
 {
 medianPtr = &list.data[i]; // original list mein wapas point karwaya
 break;
 }
 }
 cout << "Median Value: " << *medianPtr << endl;
 // ---------- Part D: Averages aur closest value ----------
 double generalAverage = (double)sum / list.size;
 double specialAverage = (double)(*minPtr + *medianPtr + *maxPtr) / 3;
 int *closestPtr = list.data;
 double smallestDistance = absValue(list.data[0] - specialAverage);
 for (int i = 0; i < list.size; i++)
 {
 double distance = absValue(list.data[i] - specialAverage);
 if (distance < smallestDistance)
 {
 smallestDistance = distance;
 closestPtr = &list.data[i];
 }
 }
 int closestPosition = closestPtr - list.data; // address ka farq = index
 cout << "General Average: " << generalAverage << endl;
 cout << "Special Average: " << specialAverage << endl;
 cout << "Closest Value: " << *closestPtr << endl;
 cout << "Position of Closest Value: " << closestPosition << endl;
 // ---------- Part E: Final calculations aur list modify karna ----------
 double averageDifference = absValue(generalAverage - specialAverage);
 double finalScore = absValue(*closestPtr - generalAverage)
 + absValue(*closestPtr - specialAverage)
 + averageDifference;
 cout << "Difference Between Averages: " << averageDifference << endl;
 cout << "Final Score: " << finalScore << endl;
 // position ko pehle hi save kar lo, delete ke baad pointer invalid ho sakta hai
 closestPosition = closestPtr - list.data;
 deleteAtPosition(list, closestPosition);
 cout << "ArrayList After Deletion: ";
 displayList(list);
 int roundedSpecial = (int)(specialAverage + 0.5); // nearest integer
 insertAtBeginning(list, roundedSpecial);
 cout << "Final ArrayList After Insertion: ";
 displayList(list);
 return 0;
}
