#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;


int main() {

    ll n; cin >> n;
    vector<ll> a(n),b(n);
    rep(i,n) cin >> a[i];

    if(n%2 == 1){
        rep(i,n){
            b[n/2 + ((i%2 == 1)?1:-1)*((i+1))/2] = a[i];
        }
    }else{
        rep(i,n){
            b[n/2 + ((i%2 == 1)?-1:1)*((i+1))/2] = a[i];
        }
    }

    rep(i,n) cout << b[i] << " ";
    return 0;
}









