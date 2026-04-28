## 6.10 LAB: All Permutations of Names

Students apply permutation logic to names rather than characters.

Key ideas:

* Print only in the base case
* Use backtracking to restore state

---

## 6.11 LAB: Number Pattern

```cpp
void pattern(int n) {
    if (n == 0)
        return;

    cout << n << " ";
    pattern(n - 1);
    cout << n << " ";
}
```

This lab highlights how output order changes depending on placement.

---

## 6.12 LAB: Count the Digits

```cpp
int countDigits(int n) {
    if (n == 0)
        return 0;
    return 1 + countDigits(n / 10);
}
```

---

## 6.13 LAB: Drawing a Right Side Up Triangle

```cpp
void triangle(int n) {
    if (n == 0)
        return;

    triangle(n - 1);

    for (int i = 0; i < n; i++)
        cout << "*";
    cout << endl;
}
```

---

## 6.14 LAB: Output a Linked List

```cpp
struct Node {
    int data;
    Node* next;
};

void printList(Node* head) {
    if (head == nullptr)
        return;

    cout << head->data << " ";
    printList(head->next);
}
```

---
