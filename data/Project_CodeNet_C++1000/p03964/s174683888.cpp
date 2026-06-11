#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;
    vector<ll> T(n);
    vector<ll> A(n);
    rep(i, n) cin >> T[i] >> A[i];

    ll Tsum = 1;
    ll Asum = 1;
    ll cnt = 1;
    rep(i, n){
        cnt = max((Tsum + T[i] - 1)/T[i], (Asum + A[i] - 1)/A[i]);
        Tsum = T[i]*cnt;
        Asum = A[i]*cnt;
    }

    cout << Tsum + Asum << endl;
    return 0;
}