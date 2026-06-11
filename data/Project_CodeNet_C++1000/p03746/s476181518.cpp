#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end())
#define VRSORT(v) sort(v.rbegin(), v.rend())
#define ll long long
#define pb(a) push_back(a)
#define INF 1000000000
#define LINF 3e18+7
#define MOD 1000000007
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

typedef vector<unsigned int>vec;
typedef vector<vec> mat;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const double PI = acos(-1.0);
const double EPS = 1e-10;

ll N,M;
vector<vector<int>> G;
vector<int> ans;
bool visited[101010];

void dfs(int v){
    ans.push_back(v+1);
    visited[v] = 1;

    for(auto nv:G[v]){
        if(!visited[nv]) return dfs(nv);
    }
    return;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>N>>M;
    G.resize(N);
    REP(i,M){
        int a,b;
        cin>>a>>b;
        --a,--b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    dfs(0);
    reverse(ans.begin(),ans.end());
    ans.pop_back();
    dfs(0);

    cout<<ans.size()<<endl;
    for(auto x:ans) cout<<x<<" ";
    cout<<endl;
}
