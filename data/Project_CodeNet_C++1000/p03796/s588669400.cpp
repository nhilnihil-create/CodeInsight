#include<bits/stdc++.h>
#include <numeric>
// #define int long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
#define MOD 1000000007
using namespace std;
using ll = long long;
typedef vector<int> vi;

signed main() {
    ll n;
    cin >> n;
    ll ans = 1;
    rep(i, n){
        if(ans * (i+1) > MOD){
            ans = (ans * (i+1)) % MOD;
        }else{
            ans *= i+1;
        }
    }


    cout << ans % MOD << endl;
}