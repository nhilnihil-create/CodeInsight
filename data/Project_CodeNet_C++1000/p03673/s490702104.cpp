#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long ;
int main(){
    deque<ll> d;
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    rep(i,n){
        if(i%2 == 1) d.push_front(a[i]);
        else d.push_back(a[i]);
    }
    if(n%2 == 0) rep(i,n) cout << d[i] << " ";
    else{
        for(int i=n-1; i>=0; i--){
            cout << d[i] << " ";
        }
    }
    cout << endl;
    

}