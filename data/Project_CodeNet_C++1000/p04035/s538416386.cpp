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
    ll n, l, p;
    cin >> n >> l;
    vector<ll> a(n);
    rep(i, n)cin >> a[i];
    bool ok = false;
    REP(i, n-1){
        if(a[i-1]+a[i] >= l){
            ok = true;
            p = i;
        }
    }
    if(!ok)cout << "Impossible" << endl;
    else{
        cout << "Possible" << endl;
        REP(i, p-1)cout << i << endl;
        for(int i = n-1; i > p; i--)cout << i << endl;
        cout << p << endl;
    }
}   