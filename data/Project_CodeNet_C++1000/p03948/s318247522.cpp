#include <iostream>
#include <vector>
using namespace std;

int N, T;

int main() {
    cin >> N >> T;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int mn = A[0];
    int profit = 0, cnt = 0;
    for (int i = 1; i < N; i++) {
        if (A[i] < mn) {
            mn = A[i];
        }
        
        if (profit == A[i] - mn) {
            cnt++;
        } else if (profit < A[i] - mn) {
            cnt = 1;
            profit = A[i] - mn;
        }
    }
    cout << cnt << endl;
}