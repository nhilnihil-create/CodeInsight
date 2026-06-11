#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n,k; cin >> n >> k;
    vector<pair<ll,ll>> a(n);
    for(int i = 0; i < n; i++) {
    int x,y; cin >> x >> y;
        pair<ll,ll> p(x,y);
        a.at(i)=p; 
    }
    sort(a.begin(),a.end());

    for(ll i = 0; i < n; i++) {
        k -= a[i].second;
        if(k<=0){
            cout << a[i].first << endl;
            return 0;
        }
    }
    return 0;
}