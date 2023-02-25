// Quick sort implementation using c++

#include <iostream>
using namespace std;

int partition(int A[], int low, int high) {
    int i, j, t, pivot = A[high];
    i = low-1;
    for (j = low; j < high; j++) {
        if (j >= 0 && A[j] < pivot) {
            i++;
            t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    }
    t = A[high];
    A[high] = A[i+1];
    A[i+1] = t;
    return i+1;
}

void quick_sort(int A[], int low, int high) {
    if (low >= high) return;
    int p = partition(A, low, high);
    quick_sort(A, low, p-1);
    quick_sort(A, p+1, high);
}

int main() {
    int A[] = {3, 1, 10, 919, 100, 8, 12, 2, 4, 5, 7, 6, 9, 28, 105};
    int i, n = 14;
    quick_sort(A, 0, n);
    for (i = 0; i <= n; i++) {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}