#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
#define P pair<int, int>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    ll ans;
    rep(i, n){
        if(i == 0){
            ans = (ll)k;
            continue;
        }
        ans *= (ll)(k-1);
    }
    cout << ans << endl;
    return 0;
}