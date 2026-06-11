#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}

int main(){
    ll N,M;
    cin >> N >> M;
    vector<vector<ll>> G(N);
    map<ll,ll> mp;
    ll a,b;
    rep(i,M){
        cin >> a >> b;
        mp[a]++;
        mp[b]++;
    }
    for(auto& e:mp){
        if(e.second%2){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}