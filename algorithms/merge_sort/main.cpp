#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;
/*
MergeSort(numbers, i, k) {
   j = 0
   if (i < k) {
      j = (i + k) / 2              // Find midpoint 
      MergeSort(numbers, i, j)     // Sort left part
      MergeSort(numbers, j + 1, k) // Sort right part
      Merge(numbers, i, j, k)      // Merge parts
   }
}
*/
void Merge(int numbers[], int i, int j, int k) {
   int mergedSize;                            // Size of merged partition
   int mergePos;                              // Position to insert merged number
   int leftPos;                               // Position of elements in left partition
   int rightPos;                              // Position of elements in right partition
   int* mergedNumbers = nullptr;

   mergePos = 0;
   mergedSize = k - i + 1;
   leftPos = i;                               // Initialize left partition position
   rightPos = j + 1;                          // Initialize right partition position
   mergedNumbers = new int[mergedSize];       // Dynamically allocates temporary array
                                              // for merged numbers
   // Add smallest element from left or right partition to merged numbers
   while (leftPos <= j && rightPos <= k) {
      if (numbers[leftPos] < numbers[rightPos]) {
         mergedNumbers[mergePos] = numbers[leftPos];
         ++leftPos;
      }
      else {
         mergedNumbers[mergePos] = numbers[rightPos];
         ++rightPos;
         
      }
      ++mergePos;
   }
   
   // If left partition is not empty, add remaining elements to merged numbers
   while (leftPos <= j) {
      mergedNumbers[mergePos] = numbers[leftPos];
      ++leftPos;
      ++mergePos;
   }
   
   // If right partition is not empty, add remaining elements to merged numbers
   while (rightPos <= k) {
      mergedNumbers[mergePos] = numbers[rightPos];
      ++rightPos;
      ++mergePos;
   }
   
   // Copy merge number back to numbers
   for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
      numbers[i + mergePos] = mergedNumbers[mergePos];
   }
   delete[] mergedNumbers;
}

void MergeSort(int numbers[], int i, int k) {
   int j;
   if (i < k) {
      j = (i + k) / 2;             // Find midpoint 
      MergeSort(numbers, i, j);    // Sort left part
      MergeSort(numbers, j + 1, k); // Sort right part
      Merge(numbers, i, j, k);     // Merge parts
   }
}

void print(int ar[],int size) {
  for(int i=0;i<size;++i) {
    cout << ar[i] << " ";
  }
  cout << endl;
}

void fillArray(int numbers[],int size) {
    for(int i=0;i< size;i++) {
        numbers[i]= rand() % 100 +1;
    }
}
const int SIZE = 50;
int main() {
    srand(time(nullptr));
    int ar[SIZE];
    fillArray(ar,SIZE);
    print(ar,SIZE);
    cout << "-------------" << endl;
    MergeSort(ar,0,SIZE-1);
    print(ar,SIZE);
    return 0;
}