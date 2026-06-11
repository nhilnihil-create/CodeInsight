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
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
    }
    ll num=0;
    ll cnt=0;
    vector<vector<ll>> s(h,vector<ll>(w));
    rep(i,h){
        if(i%2==0){
            for(ll j=0;j<w;j++){
                s[i][j]=num;
                cnt++;
                if(cnt==a[num]){
                    cnt=0;
                    num++;
                }
            }
        }
        else{
            for(ll j=w-1;j>=0;j--){
                s[i][j]=num;
                cnt++;
                if(cnt==a[num]){
                    cnt=0;
                    num++;
                }
            }
        }
    }
    rep(i,h){
        rep(j,w){
            if(j) cout << " ";
            cout << s[i][j]+1;
        }
        cout << endl;
    }
    return 0;
} 