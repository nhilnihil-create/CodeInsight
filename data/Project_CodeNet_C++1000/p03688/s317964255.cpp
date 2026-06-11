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
const ll MOD=(ll)1e9+7;
const ll MOD2=998244353;
const ld pi=3.14159265358979323846;
const ld eps=1e-10;


signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> AA(N,0);
    for(ll i=0;i<N;++i)cin>>AA[i];
    map<ll,ll> M;
    for(auto p: AA)M[p]++;
    if(M.size()>2){
        prt("No");
        return 0;
    }
    if(M.size()==1){
        if(M[AA[0]]==N&&(AA[0]==N-1||(AA[0]<=N/2&&AA[0]>=1))){
            prt("Yes");
        }
        else prt("No");
        return 0;
    }
    P A, B;
    bool check=0;
    for(auto p: M){
        if(!check){
            check=1;
            A=p;
        }
        else {
            B=p;
        }
    }
    if(B.first-A.first!=1){
        prt("No");
        return 0;
    }
    ll i=N-B.first;
    if(i+1<=B.second&&2*i>=B.second){
        prt("Yes");return 0;
    }
    prt("No");

    return 0;
}

