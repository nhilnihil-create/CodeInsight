#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    rep(i,n) cin >> a.at(i) >> b.at(i);
    ll mx=0;
    ll num=0;
    rep(i,n){
        if(mx<a.at(i)){
            mx=a.at(i);
            num=b.at(i);
        }
    }
    cout << mx+num << endl;
}
