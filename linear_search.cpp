// Linear search implementation using c++

#include <iostream>
using namespace std;

int linear_search(int A[], int n, int target) {
    int i;
    for (i = 0; i < n; i++){
        if (A[i] == target){
            return i;
        }
    }
    return -1;
}

int main() {
    int A[] = {3, 5, 1, 2, 4, 8, 10, 7, 6, 9};
    int i, target, n = 10;
    for (i = 0; i < n; i++) {
        cout<<A[i]<<" ";
    }
    cout<<"\nEnter your targeted number: ";
    cin>>target;
    int ls = linear_search(A, n, target);
    cout<<"Index of the targeted number: "<<ls<<endl;
    return 0;
}