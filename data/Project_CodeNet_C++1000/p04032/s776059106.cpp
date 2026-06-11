#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using T = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define prt(v) cout<<(v)<<"\n";
#define fi(v) get<0>(v)
#define se(v) get<1>(v)
#define th(v) get<2>(v)
#define endl "\n"
template <typename T> bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;

//dp[i][j]はi個使い和がjのもの
vector<vector<ll>> dp(51, vector<ll>(2501, 0));

signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    string s;
    cin >> s;
    ll n=s.size();
    if(n==2){
        if(s[0]==s[1]){prt("1 2")return 0;}
        else prt("-1 -1")return 0;
    }
    for(ll i=0;i<n-2;++i){
        if(s[i]==s[i+1]||s[i+1]==s[i+2]||s[i]==s[i+2]){
            cout<<i+1<<" "<<i+3<<endl;return 0;
        }
    }
    prt("-1 -1")
    
    return 0;
}
