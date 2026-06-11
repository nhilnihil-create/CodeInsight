#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for (int (i)=0; (i) < (n); (i)++)

int main()
{
    ll MOD = 1000000007;
    ll N; cin >> N;
    ll p = 1;
    rep(i,N) {
        p = (p * (i+1)) % MOD;
        //cout << p << endl;
    }
    cout << p << endl;


}
