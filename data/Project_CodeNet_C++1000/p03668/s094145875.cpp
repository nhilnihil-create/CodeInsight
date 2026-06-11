#define TEMPLATE_USED
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

ll N;
vl x;
vl y;

void solve();

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    x = vl(N-1);
    y = vl(N-1);
    for(int i = 0; i < N-1; ++i){
        cin >> x[i];
        cin >> y[i];
    }
    solve();
}

// 2 <= N <= 100000
// 1 <= x_i, y_i <= N
// 与えられるグラフは木である．

vvl g;
ll f(ll x=0,ll p=-1){
    ll ret=0;
    for(ll to:g[x]){
        if(to==p)continue;
        ret^=f(to,x)+1;
    }
    return ret;
}

// ll N, vl x, vl y
// Alice が勝つなら Alice を，Bob が勝つなら Bob を出力せよ．
void solve(){
    /* (´~`) */
    g.resize(N);
    rep(i,N-1){
        g[x[i]-1].push_back(y[i]-1);
        g[y[i]-1].push_back(x[i]-1);
    }

    cout<<(f()?"Alice":"Bob")<<endl;
}
