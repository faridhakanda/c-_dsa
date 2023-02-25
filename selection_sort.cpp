// Selection sort implementation using c++;
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

int main() {
    int A[] = {3, 5, 10, 11, 100, 9, 8, 7, 6, 4, 1, 2};
    int i, n = 12;
    selection_sort(A, n);
    for (i = 0; i < n; i++) {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}