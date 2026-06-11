#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    rep(i, N) {
        cin >> A[i];
        B[i] = A[i];
    }
    sort(B.begin(), B.end());
    map<int, int> mp;
    rep(i, N) {
        mp[B[i]] = i;
    }
    int ans = 0;
    rep(i, N) {
        ans += (mp[A[i]] + i) % 2;
    }
    cout << ans / 2 << endl;
}