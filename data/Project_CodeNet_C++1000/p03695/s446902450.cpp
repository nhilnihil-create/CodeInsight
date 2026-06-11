#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INF INT_MAX // 2147483647
#define INFLL LLONG_MAX // 9223372036854775807
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define per(i, n) for(ll i=((ll)(n))-1; i>=0; i--)
#define perf(i, n) for(ll i=((ll)(n)); i>0; i--)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
#define Init() std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout<<fixed<<setprecision(15);
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

int main(){
    Init();
    ll n; cin >> n;
    set<ll> st;
    ll free = 0;

    rep(i, n){
        ll a; cin >> a;
        if(1 <= a && a < 400) st.insert(0);
        if(400 <= a && a < 800) st.insert(1);
        if(800 <= a && a < 1200) st.insert(2);
        if(1200 <= a && a < 1600) st.insert(3);
        if(1600 <= a && a < 2000) st.insert(4);
        if(2000 <= a && a < 2400) st.insert(5);
        if(2400 <= a && a < 2800) st.insert(6);
        if(2800 <= a && a < 3200) st.insert(7);
        if(3200 <= a) free++;
    }

    // 最小値
    if(st.size()==0 && free >= 1) cout << 1 << " ";
    else cout << st.size() << " ";

    // 最大値
    cout << (ll)st.size()+free << endl;
}