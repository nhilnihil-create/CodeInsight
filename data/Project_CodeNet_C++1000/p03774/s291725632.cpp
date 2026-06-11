#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int n,m;
    cin >> n >> m;
    vector<pair<ll, ll>> a(n);
    vector<pair<ll, ll>> b(m);
    rep(i,n){
        cin >> a[i].first >> a[i].second;
    }
    rep(i,m){
        cin >> b[i].first >> b[i].second;
    }
    vector<ll> dist(n,1000000001);
    vector<ll> ans(n);
    rep(i,n){
        rep(j,m){
            if(abs(a[i].first-b[j].first)+abs(a[i].second-b[j].second) < dist[i]){
                dist[i] = abs(a[i].first-b[j].first)+abs(a[i].second-b[j].second);
                ans[i] = j+1; 
            }
        }
    }
    rep(i,n){
        cout << ans[i] << endl;
    }
    return 0;
}