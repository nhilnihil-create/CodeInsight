#include<cmath>
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
stack<int> st;
queue<int> qu;
queue<pair<int,int> > qu2;
priority_queue<int> pq;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define rep2(i,n) for(int i=1; i<=(int)(n); i++)
#define mins(x,y) x=min(x,y)
#define maxs(x,y) x=max(x,y)
#define ALL(a) a.begin(), a.end()
typedef set<int> set_t;
typedef set<string> set_g;
typedef complex<double> xy_t;
static const int NIL = -1;
static const int INF = 1000000007;
#define mp make_pair
#define sz(x) int(x.sise())
#define mod 1000000007
#define reps(i,s,n) for(int i = s; i < n; i++)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
deque<int> deq;
#define fi first
#define se second
//const ll MOD = 998244353;
const ll MOD = (1e+9) + 7;
typedef pair<int, int> P;
typedef vector<ll> vec;
typedef vector<vec> mat;

int main(){
    int n,m;
    cin >> n>> m;
    mat a(n,vec(m));
    rep(i,n) rep(j,m) cin >> a[i][j],--a[i][j];
    vector<bool> stop(m,false);
    vec id(n,0),memo(m,0);//id:iのid[i]ばんめの競技について・memo:競技の人数
    ll ans=n;
    rep(roop,m){
        rep(i,n){
            while(stop[a[i][id[i]]])++id[i];//次の競技はどうか考える
            ++memo[a[i][id[i]]];//競技参加者
        }
        auto ite = max_element(ALL(memo));//最大要素をさす最初のいてれーた
        ans = min(ans,*ite);
        stop[ite-memo.begin()]=true;//ite-memo.begin()の競技が排除
        rep(i,m)memo[i]=0;
    }
    cout<<ans<<endl;
    return 0;
}