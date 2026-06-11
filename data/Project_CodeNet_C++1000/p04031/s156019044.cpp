#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n;
    cin >> n;
    vector<ll>a(n);
    for(ll i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    ll cost=1e15;
    for(ll i=-100;i<=100;i++){
        ll x=0;
        for(ll j=0;j<n;j++){
            x+=pow(a[j]-i,2);
        }
        cost=min(cost,x);
    }
    cout << cost << endl;
}