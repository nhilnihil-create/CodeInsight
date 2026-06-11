#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll MAX = 10000000;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n; cin >> n;
    vector<ll> ans;
    for(ll i=MAX;i>=1;i--){
        if((i * (i - 1)) / 2 < n){
            ans.push_back(i);
            n -= i;
        }
    }
    for(ll a: ans) cout << a << endl;
}