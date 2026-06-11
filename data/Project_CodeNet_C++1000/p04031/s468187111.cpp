#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int N; cin >> N;
    vector<int> A(N);
    rep(i,N) cin >> A.at(i);
    sort(begin(A), end(A));
    int mi = 1<<30;
    for (int i = A[0]; i <= A[N-1]; i++) {
        int sum = 0;
        rep(j,N) sum += pow(A[j] - i, 2);
        mi = min(mi, sum);
    }
    cout << mi << endl;
}