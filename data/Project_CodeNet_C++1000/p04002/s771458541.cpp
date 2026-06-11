#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pl;
typedef vector<pl> vp;
const ll INF=1001001001;
const ll LINF=1001001001001001001;
const ll D4[]={0,1,0,-1,0};
const ll D8[]={0,1,1,0,-1,-1,1,-1,0};
#define _overload3(_1,_2,_3,name,...) name
#define _rep2(i,n) for(ll i=0;i<(n);++i)
#define _rep3(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(...) _overload3(__VA_ARGS__,_rep3,_rep2)(__VA_ARGS__)
#define _repe2(i,n) for(ll i=0;i<=(n);++i)
#define _repe3(i,a,b) for(ll i=(a);i<=(b);++i)
#define repe(...) _overload3(__VA_ARGS__,_repe3,_repe2)(__VA_ARGS__)
#define _rrep2(i,n) for(ll i=(n)-1;i>=0;i--)
#define _rrep3(i,a,b) for(ll i=(b)-1;i>=(a);i--)
#define rrep(...) _overload3(__VA_ARGS__,_rrep3,_rrep2)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
template<class T>
bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>
bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}
template<class T>
using pq=priority_queue<T,vector<T>,greater<T>>;

ll H;
ll W;
ll N;
vl a;
vl b;

void solve();

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> H;
    cin >> W;
    cin >> N;
    a = vl(N);
    b = vl(N);
    for(int i = 0; i < N; ++i){
        cin >> a[i];
        cin >> b[i];
        --a[i],--b[i];
    }
    solve();
}

// ll H, ll W, ll N, vl a, vl b
void solve(){
    map<ll,ll> mp;
    rep(i,N)repe(j,-1,1)repe(k,-1,1){
        ll ty=a[i]+j,tx=b[i]+k;
        if(ty<1||ty>=H-1||tx<1||tx>=W-1)continue;
        mp[ty*W+tx]++;
    }
    vl ans(10);
    ans[0]=(H-2)*(W-2);
    for(auto &p:mp)++ans[p.second],--ans[0];
    rep(i,10)cout<<ans[i]<<endl;
}
