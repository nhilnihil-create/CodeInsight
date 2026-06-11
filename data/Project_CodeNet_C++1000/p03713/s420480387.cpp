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

P F(ll h,ll w){
    if(abs(h/2*w-((h-h/2)*w))<abs(w/2*h-((w-w/2)*h)))
    return P(h/2*w,((h-h/2)*w));
    return P(w/2*h,((w-w/2)*h));
}

signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ll H;
    cin >> H;
    ll W;
    cin >> W;
    ll ans=INF;
    chmin(ans,max({F(H-H/3,W).first,F(H-H/3,W).second,H/3*W})-min({F(H-H/3,W).first,F(H-H/3,W).second,H/3*W}));
    chmin(ans,max({F(H-H/3-1,W).first,F(H-H/3-1,W).second,(H/3+1)*W})-min({F(H-H/3-1,W).first,F(H-H/3-1,W).second,(H/3+1)*W}));
    chmin(ans,max({F(W-W/3,H).first,F(W-W/3,H).second,W/3*H})-min({F(W-W/3,H).first,F(W-W/3,H).second,W/3*H}));
    chmin(ans,max({F(W-W/3-1,H).first,F(W-W/3-1,H).second,(W/3+1)*H})-min({F(W-W/3-1,H).first,F(W-W/3-1,H).second,(W/3+1)*H}));
    prt(ans)

    return 0;
}
