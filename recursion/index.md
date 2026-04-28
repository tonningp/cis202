# Chapter 6: Recursion in C++

These notes introduce recursion in C++ with clear explanations, examples, and lab-aligned applications.

---

## 6.1 Recursion: Introduction

**Recursion** is a programming technique in which a function calls itself in order to solve a problem by breaking it into smaller subproblems.

Every recursive function must contain:

* A **base case**: stops the recursion
* A **recursive case**: makes progress toward the base case

### Example: Countdown

```cpp
#include <iostream>
using namespace std;

void countdown(int n) {
    if (n == 0) {
        cout << "Blast off!" << endl;
        return;
    }
    cout << n << endl;
    countdown(n - 1);
}

int main() {
    countdown(5);
    return 0;
}
```

---

## 6.2 Recursive Functions

Recursive functions are syntactically no different from regular functions. The only difference is that they call themselves.

### Warning: Infinite Recursion

```cpp
void badRecursion(int n) {
    cout << n << endl;
    badRecursion(n);   // No base case!
}
```

Without a valid base case, the program will eventually crash.

---

## 6.3 Recursive Algorithm: Search

Recursion works naturally with data structures like arrays, linked lists, and trees.

### Recursive Linear Search Example

```cpp
bool linearSearch(int arr[], int size, int target) {
    if (size == 0)
        return false;

    if (arr[0] == target)
        return true;

    return linearSearch(arr + 1, size - 1, target);
}
```

---

## 6.4 Adding Output Statements for Debugging

Debugging recursion can be challenging since many instances of the function exist on the call stack at once.

### Debugging Example: Factorial

```cpp
int factorial(int n) {
    cout << "Entering factorial(" << n << ")" << endl;

    if (n == 0)
        return 1;

    int result = n * factorial(n - 1);
    cout << "Returning " << result << " from factorial(" << n << ")" << endl;
    return result;
}
```

---

## 6.5 Creating a Recursive Function

Design steps:

1. Identify the smallest possible input (base case)
2. Reduce the problem
3. Call the function recursively

### Example: Sum from 1 to n

```cpp
int sum(int n) {
    if (n == 0)
        return 0;
    return n + sum(n - 1);
}
```

---

## 6.6 Recursive Math Functions

### Factorial

```cpp
int factorial(int n) {
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}
```

### Fibonacci (inefficient example)

```cpp
int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
```

---

## 6.7 Recursive Exploration of All Possibilities

Recursion is often used to explore all possible combinations.

### Binary String Generation

```cpp
void generate(string s, int n) {
    if (n == 0) {
        cout << s << endl;
        return;
    }

    generate(s + "0", n - 1);
    generate(s + "1", n - 1);
}
```

---

## 6.8 Stack Overflow

Each recursive call consumes stack memory. Without a reachable base case, programs will crash due to stack overflow.

```cpp
void overflow() {
    overflow();
}
```

---

## 6.9 C++ Example: Recursively Output Permutations

```cpp
void permute(string s, int start) {
    if (start == s.length() - 1) {
        cout << s << endl;
        return;
    }

    for (int i = start; i < s.length(); i++) {
        swap(s[start], s[i]);
        permute(s, start + 1);
        swap(s[start], s[i]); // backtrack
    }
}
```


## Chapter Summary

* Recursion breaks problems into smaller self-similar parts
* Every recursive function must:

  * Have a base case
  * Make progress toward that base case
* Recursion is especially effective for:

  * Trees
  * Linked lists
  * Permutations and combinations
* Understanding the call stack is essential to mastering recursion
