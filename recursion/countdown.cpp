#include <iostream>
using namespace std;

void countdown(int& n) {
    int n2 = n; // Create a copy of n to avoid modifying the original variable
    if (n == 0) {
        cout << "Blast off!" << endl;
        return;
    }
    cout << n << endl;
    countdown(n2);
}

int main() {
    int n = 5;
    countdown(n);
    return 0;
}
