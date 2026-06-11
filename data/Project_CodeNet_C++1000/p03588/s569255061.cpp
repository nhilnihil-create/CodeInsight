#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define REP(i,n) for (ll i = 0; i < (n); ++i)


int main(){
    ll n;
    cin >> n;
    ll ans = 0;
    ll max_a = 0;
    REP(i, n){
        ll ai, bi;
        cin >> ai >> bi;
        if(ai > max_a){
            ans = ai + bi;
            max_a = ai;
        }
    }
    cout << ans << endl;
    return 0;
}
