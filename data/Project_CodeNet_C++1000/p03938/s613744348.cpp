#include <bits/stdc++.h>
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

int main() {
    ll n;
    cin >> n;
    vector<int> p(n);
    rep(i, n)cin >> p[i];
    vector<ll> a(n), b(n);
    REP(i, n)a[i-1] = n*i;
    for(int i = n-1; i >= 0; i--)b[i] = (n-i) * n;
    rep(i, n){
        b[p[i]-1] += i+1;
    } 
    rep(i, n)cout << a[i] << " ";
    cout << endl;
    rep(i, n)cout << b[i] << " ";
    cout << endl;
}      