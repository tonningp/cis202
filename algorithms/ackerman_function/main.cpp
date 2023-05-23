// C++ program to illustrate Ackermann function
#include <iostream>
using namespace std;
 
int ack(int m, int n)
{
    if (m == 0){
        cout << n << " + " << 1 << endl;
        return n + 1;
    }
    else if((m > 0) && (n == 0)){
        cout << "ack(" <<m-1<< "," << 1<< ")" << endl;
        return ack(m - 1, 1);
    }
    else if((m > 0) && (n > 0)){
        cout << "ack(" << m-1 << ",ack("<< m << "," << n -1 <<"))" << endl;
        return ack(m - 1, ack(m, n - 1));
    }
    return 0;
}
 
int main()
{
    int m;
    int n;
    cin >> m >> n;
    int A = ack(m, n);
    cout << A << endl;
    return 0;
}