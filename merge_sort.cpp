// Merge sort implementation using c++;
#include <iostream>
using namespace std;

void merge(int A[], int low, int mid, int high) {
    int i, index_a, index_l, index_r, size_l, size_r;
    size_l = mid-low+1;
    size_r = high-mid;
    int L[size_l], R[size_r];
    for (i = 0; i < size_l; i++) {
        L[i] = A[low+i];
    }
    for (i = 0; i < size_r; i++) {
        R[i] = A[mid+i+1];
    }

    index_l = 0;
    index_r = 0;
    for (index_a = low; index_l < size_l && index_r < size_r; index_a++) {
        if (L[index_l] < R[index_r]) {
            A[index_a] = L[index_l];
            index_l++;
        } else {
            A[index_a] = R[index_r];
            index_r++;
        }
    }
    while (index_l < size_l) {
        A[index_a] = L[index_l];
        index_a++;
        index_l++;
    }
    while (index_r < size_r) {
        A[index_a] = R[index_r];
        index_a++;
        index_r++;
    }
}

void merge_sort(int A[], int low, int high) {
    if (low >= high) {
        return;
    }
    int mid = low+(high-low)/2;
    merge_sort(A, low, mid);
    merge_sort(A, mid+1, high);
    merge(A, low, mid, high);
}

int main() {
    int A[] = {3, 10, 100, 92, 143, 1, 2, 4, 5, 8, 9, 18, 52};
    int i, n = 12;
    merge_sort(A, 0, n);
    for (i = 0; i <= n; i++) {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}