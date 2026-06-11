#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    ll N; cin >> N;
    vector<ll> A(3*N);
    ll sumA = 0, sumB = 0;
    vector<ll> a(N+1, 0);
    priority_queue<ll, vector<ll>, greater<ll>> AA;
    priority_queue<ll> AB;
    rep(i,3*N) {
        cin >> A.at(i);
        if (i >= 0 && i < N) {
            sumA += A[i];
            AA.emplace(A[i]);
        } else if (i >= 2*N) {
            sumB += A[i];
            AB.emplace(A[i]);
        }
    }
    a[0] = sumA;
    a[N] = -sumB;
    for (int i = 0; i < N; i++) {
        AA.push(A[N+i]);
        sumA += A[N+i];
        ll mi = AA.top(); AA.pop();
        sumA -= mi;
        a[i+1] += sumA;
        AB.push(A[2*N-1 - i]);
        sumB += A[2*N-1 - i];
        ll ma = AB.top(); AB.pop();
        sumB -= ma;
        a[N-1 - i] -= sumB;
    }
    ll ma = INT64_MIN;
    rep(i,N+1) {
        ma = max(ma, a[i]);
    }
    cout << ma << endl;
}
