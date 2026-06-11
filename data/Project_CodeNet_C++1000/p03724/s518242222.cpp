#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using P = pair<ll,ll>;
using um = unordered_map<ll,ll>;
#define fl cout<<flush;
#define endl '\n'
template <typename T> inline void prt(T v){cout<<v<<'\n';}
template <typename T> inline bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> inline bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1e9+7;
const ll MOD2=998244353;
const ld pi=3.14159265358979323846;
const ld eps=1e-10;



signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll M;
    cin >> M;
    vector<ll> a(M,0);
    vector<ll> b(M,0);
    for(ll i=0;i<M;++i){
        cin>>a[i]>>b[i];
        a[i]--;b[i]--;
    }
    um Ma;
    for(ll i=0;i<M;++i){
        Ma[a[i]]++;
        Ma[b[i]]++;
    }
    for(auto p: Ma){
        if(p.second%2!=0){
            prt("NO");return 0;
        }
    }
    prt("YES");

    return 0;
}

