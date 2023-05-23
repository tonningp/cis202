#include<iostream>
#include<string>
#include<deque>

using namespace std;

int main() {
    deque<string> tripRoute;

    cout << "Depart Tokyo" << endl;
    tripRoute.push_front("Tokyo");

    cout << "Transfer at Osaka" << endl;
    tripRoute.push_front("Osaka");

    cout << "Arrive in Nara" << endl;
    tripRoute.push_front("Nara");

    cout << "\nReturn trip: " << endl;
    cout << "Depart " + tripRoute.front() << endl;
    tripRoute.pop_front();

    cout << "Transfer at " + tripRoute.front() << endl;
    tripRoute.pop_front();

    cout << "Arrive in " + tripRoute.front() << endl;
    tripRoute.pop_front();

}