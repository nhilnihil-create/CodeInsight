#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();


int main() {
    int n;
    cin >> n;
    vector<ll> T(n, 0);
    vector<ll> A(n, 0);
    for(ll& val: T)
        cin >> val;
    for(ll& val: A)
        cin >> val;
    ll M = T.back();
    if (A[0] != M) {
        cout << 0 << endl;
        return 0;
    }
    ll ans = 1;
    ll mod = 1e9 + 7;
    int T_idx = -1, A_idx = n;
    for(int i = 0; i < n; i++) {
        if (T[i] == M && T_idx == -1)
            T_idx = i;
    }
    for(int i = n-1; i >= 0; i--) {
        if (A[i] == M && A_idx == n)
            A_idx = i;
    }
    if (T_idx > A_idx) {
        cout << 0 << endl;
        return 0;
    }
    for(int i = 1; i < n-1; i++) {
        if (i < T_idx && T[i] == T[i-1])
            ans *= T[i];
        else if (i > A_idx && A[i] == A[i+1])
            ans *= A[i];

        else if (i > T_idx && i < A_idx)
            ans *= T.back();
        ans %= mod;

    }
    cout << ans << endl;
    return 0;
}


