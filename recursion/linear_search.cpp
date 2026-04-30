#include <iostream>

using namespace std;


int linearSearch(int arr[], int size, int target) {
    static int index = 0;
    cout << "Index: " << index << ", Size: " << size << endl;
    if (size == 0)
        return -1;

    if (arr[0] == target)
        return index;
    index++;
    linearSearch(arr + 1, size - 1, target);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 3;

    int result = linearSearch(arr, size, target);
    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found in the array." << endl;

    return 0;
}
