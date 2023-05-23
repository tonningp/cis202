#include<iostream>

using namespace std;

int bin_search(int ar[],int key,int low,int high)
{
    int mid = (low+high)/2;
    if(low>high) return -1;
    else if(ar[mid]<key) return bin_search(ar,key,low+1,high);
    else if(ar[mid]>key) return bin_search(ar,key,low,high+1);
    else return mid;
}

int main () {
    int ar[10] = {2,4,5,7,8,10,25,35,45,54};

    int index = bin_search(ar,35,0,10);
    cout << index << endl;

    return 0;
}