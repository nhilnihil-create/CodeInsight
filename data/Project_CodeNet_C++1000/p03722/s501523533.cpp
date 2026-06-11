//header{{{
#include<bits/stdc++.h>
  
using namespace std;
 
#define rep(i,n) for(int i=0;i<(n);++i)
#define reps(i,n) for(int i=1;i<=(n);++i)
#define all(x) (x).begin(),(x).end()
#define Fixed fixed << setprecision(12)
#define int int64_t
using pii = pair<int,int>;
constexpr int INF  = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr int mod = 1e9+7; 
constexpr int MOD = 998244353;

template <class A, class B> inline bool chmax(A &a, const B &b) { return b > a && (a = b, true); }
template <class A, class B> inline bool chmin(A &a, const B &b) { return b < a && (a = b, true); }

template <class T> using min_heap = priority_queue<T,vector<T>,greater<T> >;
template <class T> using max_heap = priority_queue<T>;
template <class A, class B> using umap = unordered_map<A,B>;
  
int gcd(int a,int b){ return b ? gcd(b,a % b) : a;}
int lcm(int a,int b){ return a / gcd(a,b) * b;}

constexpr int dx[] = {1,0,-1,0,1,1,-1,-1};
constexpr int dy[] = {0,-1,0,1,1,-1,-1,1};
//}}}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,m;
    cin >> n >> m;

    vector<vector<pii> > g(n+1);
    vector<int> max_cost(n+1,-LINF);

    rep(i,m){
        int a,b,c;
        cin >> a >> b >> c;
        g[a].emplace_back(b,c);
    }

    max_cost[1] = 0;

    rep(i,n * 2){
        reps(j,n){
            rep(k,g[j].size()){
                int now = j;
                if(max_cost[now] == -LINF) continue;
                int next = g[j][k].first;
                int cost = g[j][k].second;
                if(chmax(max_cost[next],max_cost[now] + cost)){
                    if(i == n*2-1 && next == n) return cout << "inf\n",0;
                }
            }
        }
    }

    cout << max_cost[n] << '\n';

    return 0;
}
