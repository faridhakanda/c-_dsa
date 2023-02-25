// bubble sort implementation using cpp
#include <iostream>
using namespace std;

void bubble_sort(int A[], int n) {
    int i, j, t;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n-1; j++) {
            if (A[j] > A[j+1]) {
                t = A[j];
                A[j] = A[j+1];
                A[j+1] = t;
            }
        }
    }
}

int main() {
    int A[] = {2, 5, 1, 3, 4, 8, 9, 12, 38, 10, 7, 6};
    int i, n = 12;
    bubble_sort(A, n);
    for (i = 0; i < n; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;

    return 0;
}