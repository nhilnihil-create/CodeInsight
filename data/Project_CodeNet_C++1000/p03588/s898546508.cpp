#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int f(int arr[], int n) {
    int max = arr[0];
    int idx = 0;
    for(int i = 1; i < n; i++) {
        if(max < arr[i]) {
            max = arr[i];
            idx = i;
        }
    }
    return idx;
}

int main() {
    // 制約見て！！！デカかったらlong longにすること！
    int N;
    cin >> N;
    int A[N], B[N];
    rep(i, N) { cin >> A[i] >> B[i]; }
    int idx = f(A,N);

    int minB = B[idx];
    
    cout << A[idx]+minB << endl;
}