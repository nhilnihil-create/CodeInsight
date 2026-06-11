#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pll pair<ll,ll>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))

using namespace std;

template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

const ll mod=1e9+7;


int main(){
    ll h,w;
    cin >> h >> w;
    vector<vector<char>> ans(h+2,vector<char>(w+2));
    rep(i,h+2){
        rep(j,w+2){
            if(i%(h+1)==0 || j%(w+1)==0){
                ans[i][j]='#';
            }
            else{
                cin >> ans[i][j];
            }
        }
    }
    rep(i,h+2){
        rep(j,w+2){
            cout << ans[i][j];
        }
        cout << endl;
    }
}