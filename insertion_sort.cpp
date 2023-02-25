// Insertion sort implementation using c++
#include <iostream>
using namespace std;

void insertion_sort(int A[], int n) {
    int i, j, t;
    for (i = 0; i < n; i++) {
        t = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > t) {
            A[j+1] = A[j];
            j = j - 1;
        }
        A[j+1] = t;
    }
}

int main() {
    int A[] = {3, 5, 1, 2, 4, 8, 9, 10, 7, 6};
    int i, n = 10;
    insertion_sort(A, n);
    for (i = 0; i < n; i++) {
        cout<<A[i]<<" ";
    }
    cout<<endl;

    return 0;
}