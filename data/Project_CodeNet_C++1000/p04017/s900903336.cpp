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

ll N,L,Q;
vl x,a,b,pos,ans;
vvl g,q;

void solve();

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    x=vl(N);
    for(int i = 0; i < N; ++i){
        cin >> x[i];
    }
    cin >> L;
    cin >> Q;
    a=vl(Q);
    b=vl(Q);
    for(int i = 0; i < Q; ++i){
        cin >> a[i];
        cin >> b[i];
    }
    solve();
}

void dfs(ll i){
    pos.push_back(-x[i]);
    for(ll id:q[i]){
        ans[id]=pos.end()-upper_bound(all(pos),-x[max(a[id],b[id])]);
    }
    for(ll to:g[i])dfs(to);
    pos.pop_back();
}
void solve(){
    g=vvl(N);
    rep(i,N-1){
        ll idx=upper_bound(all(x),x[i]+L)-x.begin()-1;
        g[idx].push_back(i);
    }
    q=vvl(N);
    rep(i,Q){
        --a[i],--b[i];
        q[min(a[i],b[i])].push_back(i);
    }
    ans=vl(Q);
    dfs(N-1);

    rep(i,Q)cout<<ans[i]<<endl;
}

