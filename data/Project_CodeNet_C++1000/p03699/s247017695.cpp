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

const ll INF=1e10+100;

int main()
{
    ll n;
    cin >> n;
    vector<ll> s;
    ll sum_ten=0;
    ll sum_other=0;
    rep(i,n){
        ll x;
        cin >> x;
        if(x%10==0){
            sum_ten+=x;
        }
        else{
            s.push_back(x);
            sum_other+=x;
        }
    }
    if(s.size()==0){
        cout << 0 << endl;
        return 0;
    }
    
    sort(s.begin(),s.end());
    if(sum_other%10==0){
        cout << sum_other+sum_ten-s[0] << endl;
    }
    else{
        cout << sum_other+sum_ten << endl;
    }
    
    return 0;
} 