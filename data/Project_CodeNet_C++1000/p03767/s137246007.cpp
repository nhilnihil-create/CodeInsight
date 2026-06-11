#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main(){
    ll n;
    cin >> n;
    ll sum = 0;
    vector<ll> a(3*n);
    rep(i,3*n) cin >> a[i];
    sort(a.rbegin(),a.rend());
    rep(i,n){
        sum += a[2*i+1];
    }
    cout << sum << endl;
}
