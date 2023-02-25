// Binary Search Implementation iterative way using c++
#include <iostream>
using namespace std;

void selection_sort(int A[], int n) {
    int i, j, t, index;
    for (i = 0; i < n; i++) {
        index = i;
        for (j = i+1; j < n; j++) {
            if (A[j] < A[index]) {
                index = j;
            }
        }
        if (index != i) {
            t = A[i];
            A[i] = A[index];
            A[index] = t;
        }
    }
}

int binary_search_iterative(int A[], int n, int target) {
    int low = 0, high = n;
    while (low <= high){
        int mid = low+(high-low)/2;
        if (A[mid] == target) {
            return mid;
        }
        else if (A[mid] < target) {
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    return -1;
}


int main() {
    int A[] = {3, 10, 19, 32, 1, 4, 5, 8, 9, 6, 7, 11};
    int i, target, n = 12;
    selection_sort(A, n);
    for (i = 0; i < n; i++) {
        cout<<A[i]<<" ";
    }
    cout<<"\nEnter your targeted number: ";
    cin>>target;
    int bs = binary_search_iterative(A, n, target);
    cout<<"Index of the targeted number: "<<bs<<endl;

    return 0;
}