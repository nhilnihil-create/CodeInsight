#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;
using ll = long long;
int mod = 1000000007;

void solve();

int main(void){
    string A; cin >> A;
    ll lenA = A.length();
    ll alp[26] = {0};
    rep(i, lenA){
        alp[A[i] - 'a']++;
    }
    ll ans = lenA * (lenA-1) / 2 + 1; //何もしない + nC2
    rep(i, 26){
        ans -= alp[i]*(alp[i]-1)/2;
    }
    cout << ans << endl;
    return 0;
}

void solve(){}