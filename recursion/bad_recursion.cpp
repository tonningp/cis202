#include<iostream>
#include<cstdlib>
#include<ctime>


int random(int min, int max) {
    return min + rand() % (max - min + 1);
}

void bad_recursion(int n) {
    if (n == 0) {
        return;
    }
    int r = random(1, 10);
    std::cout << "n: " << n << ", r: " << r << std::endl;
    bad_recursion(n - r);
}

void good_recursion(int n) {
    if (n == 0) {
        return;
    }
    int r = random(1, 10);
    std::cout << "n: " << n << ", r: " << r << std::endl;
    good_recursion(std::max(0, n - r));
}

int main() {
    srand(time(0));
    /*
    std::cout << "Bad Recursion:" << std::endl;
    bad_recursion(50);
    */
    std::cout << "Good Recursion:" << std::endl;
    good_recursion(50);
    return 0;
}
