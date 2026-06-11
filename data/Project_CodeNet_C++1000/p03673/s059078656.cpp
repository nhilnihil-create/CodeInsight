#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define ll long long

int main(){
    int n; cin >> n;
    vector<ll> a(n),b(n,-1);
    rep(i,n) cin >> a[i];
    rep(i,n){
        if(i%2){
            b[n/2-i/2-1] = a[i];
        }else{
            b[n/2+i/2] = a[i];
        }
    }
    if(n%2) reverse(b.begin(),b.end());
    rep(i,n) cout << b[i] << ' ';
    cout << endl;
}