/*#include <iostream>
using namespace std;

int main() {
    int x = 10;

    // ref is a reference to x.
    int& ref = x;

    // printing value using ref
    cout << ref << endl;
    
    // Changing the value and printing again
    ref = 22;
    cout << ref;

    return 0;
}*/
/*#include <iostream>
using namespace std;

void modifyValue(int &x) {
  
    // Modifies the original variable
    x = 20;  
}

int main() {
    int a = 10;
  
    // Pass a by reference
    modifyValue(a);
    
    cout << a;
    return 0;
}*/
/*#include <iostream>
using namespace std;

int& getMax(int &a, int &b) {
  
    // Return the larger of the two numbers
    return (a > b) ? a : b;  
}

int main() {
    int x = 10, y = 20;
    int &maxVal = getMax(x, y);
  
    // Modify the value of the larger number
    maxVal = 30;  
    cout << "x = " << x << ", y = " << y;
    return 0;
}
*/
/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vect;
    vect.push_back(10);
    vect.push_back(20);
    vect.push_back(30);
    vect.push_back(40);

    for (int i = 0; i < vect.size(); i++) {
        vect[i] = vect[i] + 5;
    }

    for (int i = 0; i < vect.size(); i++) {
        cout << vect[i] << " ";
    }

    return 0;
}*/


