// Binary Search implementation Recursive way using c++
// and use here insertion sort
#include <iostream>
using namespace std;

void insertion_sort(int A[], int n) {
    int i, j, t;
    for (i = 0; i < n; i++) {
        t = A[i];
        j = i - 1;
        while(j >= 0 && A[j] > t) {
            A[j+1] = A[j];
            j = j - 1;
        }
        A[j+1] = t;
    }
}

int binary_search_recursive(int A[], int low, int high, int target) {
    if (high >= low){
        int mid = low+(high-low)/2;
        if (A[mid] == target) {
            return mid;
        }
        if (A[mid] < target) {
            return binary_search_recursive(A, mid+1, high, target);
        } else {
            return binary_search_recursive(A, low, mid-1, target);
        }
    }
    
    return -1;
}

int main() {
    int A[] = {3, 10, 1, 2, 4, 8, 9, 5, 77, 6, 13, 51};
    int i, target, n = 12;
    insertion_sort(A, n);
    for (i = 0; i < n; i++) {
        cout<<A[i]<<" ";
    }
    cout<<"\nEnter your targeted number: ";
    cin>>target;
    int bsr = binary_search_recursive(A, 0, n, target);
    cout<<"Index number is: "<<bsr<<endl;

    return 0;
}