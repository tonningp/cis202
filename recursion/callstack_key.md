````markdown
# Recursion Call-Stack Visualization Worksheet (C++)

Name: ____________________________  
Course / Section: ________________  
Date: ____________________________

---

## Instructions

For each problem:

1. Trace every recursive function call.
2. Draw the call stack as the program runs.
3. Record:
   - Function arguments
   - Return values
   - Output, if any
4. Pay close attention to:
   - When base cases are reached
   - The order in which calls return, also called stack unwinding

---

# Part 1: Understanding Call Order

## Problem 1: Simple Countdown

```cpp
void countdown(int n) {
    if (n == 0) {
        cout << "Done" << endl;
        return;
    }
    cout << n << endl;
    countdown(n - 1);
}
````

### Function Call

```cpp
countdown(3);
```

### Output

```text
3
2
1
Done
```

### Call Stack Trace

At maximum depth:

| Stack Level | Function Call  |
| ----------- | -------------- |
| Top         | `countdown(0)` |
|             | `countdown(1)` |
|             | `countdown(2)` |
|             | `countdown(3)` |
| Bottom      | `main()`       |

### Reflection Questions

1. How many times is `countdown()` called?
   `countdown()` is called **4 times**: `countdown(3)`, `countdown(2)`, `countdown(1)`, and `countdown(0)`.

2. Which call prints `"Done"`?
   `countdown(0)` prints `"Done"`.

---

# Part 2: Return Values and Stack Unwinding

## Problem 2: Factorial

```cpp
int factorial(int n) {
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}
```

### Function Call

```cpp
int result = factorial(3);
```

### Call Stack at Maximum Depth

| Stack Level | Function Call  | Waiting For        |
| ----------- | -------------- | ------------------ |
| Top         | `factorial(0)` | Base case          |
|             | `factorial(1)` | `1 * factorial(0)` |
|             | `factorial(2)` | `2 * factorial(1)` |
|             | `factorial(3)` | `3 * factorial(2)` |
| Bottom      | `main()`       | `factorial(3)`     |

### Return Trace

| Returning From | Returned Value |
| -------------- | -------------- |
| `factorial(0)` | `1`            |
| `factorial(1)` | `1 * 1 = 1`    |
| `factorial(2)` | `2 * 1 = 2`    |
| `factorial(3)` | `3 * 2 = 6`    |

### Final Result

```cpp
result = 6;
```

---

# Part 3: Output Before and After Recursion

## Problem 3: Number Pattern

```cpp
void pattern(int n) {
    if (n == 0)
        return;

    cout << n << " ";
    pattern(n - 1);
    cout << n << " ";
}
```

### Function Call

```cpp
pattern(3);
```

### Output

```text
3 2 1 1 2 3
```

### Call Stack Visualization

| Step | Action                  |
| ---- | ----------------------- |
| 1    | `pattern(3)` prints `3` |
| 2    | `pattern(2)` prints `2` |
| 3    | `pattern(1)` prints `1` |
| 4    | `pattern(0)` returns    |
| 5    | `pattern(1)` prints `1` |
| 6    | `pattern(2)` prints `2` |
| 7    | `pattern(3)` prints `3` |

### Call Stack at Maximum Depth

| Stack Level | Function Call |
| ----------- | ------------- |
| Top         | `pattern(0)`  |
|             | `pattern(1)`  |
|             | `pattern(2)`  |
|             | `pattern(3)`  |
| Bottom      | `main()`      |

---

# Part 4: Multiple Recursive Calls

## Problem 4: Fibonacci

```cpp
int fib(int n) {
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}
```

### Function Call

```cpp
fib(4);
```

### Recursive Call Tree

```text
fib(4) = 3
├── fib(3) = 2
│   ├── fib(2) = 1
│   │   ├── fib(1) = 1
│   │   └── fib(0) = 0
│   └── fib(1) = 1
└── fib(2) = 1
    ├── fib(1) = 1
    └── fib(0) = 0
```

### Return Trace

| Function Call | Returned Value |
| ------------- | -------------- |
| `fib(1)`      | `1`            |
| `fib(0)`      | `0`            |
| `fib(2)`      | `1 + 0 = 1`    |
| `fib(1)`      | `1`            |
| `fib(3)`      | `1 + 1 = 2`    |
| `fib(1)`      | `1`            |
| `fib(0)`      | `0`            |
| `fib(2)`      | `1 + 0 = 1`    |
| `fib(4)`      | `2 + 1 = 3`    |

### Total Function Calls

```text
fib() was called 9 times.
```

---

# Part 5: Linked List Recursion

## Problem 5: Output a Linked List

```cpp
void printList(Node* head) {
    if (head == nullptr)
        return;

    cout << head->data << " ";
    printList(head->next);
}
```

### List Structure

```text
[10] → [20] → [30] → nullptr
```

### Call Stack Trace

At maximum depth:

| Stack Level | Function Call                   | `head->data` |
| ----------- | ------------------------------- | ------------ |
| Top         | `printList(nullptr)`            | N/A          |
|             | `printList(node containing 30)` | `30`         |
|             | `printList(node containing 20)` | `20`         |
|             | `printList(node containing 10)` | `10`         |
| Bottom      | `main()`                        | N/A          |

### Output

```text
10 20 30
```

---

# Final Reflection

## 1. Why must every recursive function have a base case?

Every recursive function must have a base case because the base case tells the function when to stop calling itself. Without a base case, the function will continue making recursive calls until the program runs out of stack memory and crashes.

## 2. What happens in memory when recursion goes too deep?

Each recursive function call adds a new stack frame to memory. That stack frame stores information such as function arguments, local variables, and the location where the function should return. If recursion goes too deep, too many stack frames are created, which can cause a stack overflow.

## 3. When is recursion a better choice than loops?

Recursion is often a better choice when the problem naturally breaks into smaller versions of the same problem. This is common with trees, linked lists, directory structures, search problems, permutations, combinations, and backtracking problems.

---

# Instructor Notes

If you cannot explain recursion using a call stack, you do not yet understand recursion.

```
```
