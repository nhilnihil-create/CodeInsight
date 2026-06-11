#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using Tup = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define prt(v) cout<<(v)<<"\n";
#define fl cout<<flush;
#define fi(v) get<0>(v)
#define se(v) get<1>(v)
#define th(v) get<2>(v)
#define endl "\n"
template <typename T> bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;

signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    string S;
    cin >> S;
    string T;
    cin >> T;
    ll s=S.size();
    ll t=T.size();
    //sA[i]はS[i-1]までのAの個数
    vector<ll> sA(s+1,0);   
    vector<ll> sB(s+1,0);

    vector<ll> tA(t+1,0);
    vector<ll> tB(t+1,0);

    for(ll i=1;i<=s;++i){
        sA[i]=sA[i-1];
        sB[i]=sB[i-1];
        if(S[i-1]=='A')sA[i]++;
        else sB[i]++;
    }
    for(ll i=1;i<=t;++i){
        tA[i]=tA[i-1];
        tB[i]=tB[i-1];
        if(T[i-1]=='A')tA[i]++;
        else tB[i]++;
    }
    ll q;
    cin >> q;
    for(ll i=0;i<q;++i){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        a--;b--;c--;d--;
        ll K=sA[b+1]-sA[a]-tA[d+1]+tA[c];
        ll L=sB[b+1]-sB[a]-tB[d+1]+tB[c];
        if((L-K+3000000000)%3==0)prt("YES")
        else prt("NO")
    }

    return 0;
}
