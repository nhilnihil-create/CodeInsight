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

const ll INF=1e18;

int main(){
    string a,b;
    cin >> a >> b;
    if(a.length()>b.length()){
        cout << "GREATER" << endl;
        return 0;
    }
    if(a.length()<b.length()){
        cout << "LESS" << endl;
        return 0;
    }
    ll n=a.length();
    rep(i,n){
        ll p=a[i]-'0';
        ll q=b[i]-'0';
        if(p>q){
            cout << "GREATER" << endl;
            return 0;
        }
        if(p<q){
            cout << "LESS" << endl;
            return 0;
        }
    }
    cout << "EQUAL" << endl;
    
    return 0;
}
