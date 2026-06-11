#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
using ld = long double;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define siz(v) (ll)(v).size()
#define rep(i,a,n) for(ll i=a;i<(ll)(n);i++)
#define repr(i,a,n) for(ll i=n-1;(ll)a<=i;i--)
#define lb lower_bound
#define ub upper_bound
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
const ll mod = 1000000007;
const ll INF = 1000000099;
const ll LINF = (ll)(1e18 +99);
vector<ll> dx={-1,1,0,0},dy={0,0,-1,1};
template<typename T>T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<typename T>T mpow(T a, T n) {
   T res = 1;
   for(;n;n>>=1) {
      if (n & 1) res = res * a;
      a = a * a;
   }
   return res;
}

//cin.tie(0);ios::sync_with_stdio(false);

vector<vector<int>> v(100010,vector<int>(0));

int dp[100010]={};

int dfs(int now){
    priority_queue<int> q;

    rep(i,0,siz(v[now])){
        if(dp[v[now][i]]==0){
            dp[v[now][i]]=dfs(v[now][i]);
        }
        q.push(dp[v[now][i]]);
    }

    if(siz(v[now])==0)return 0;

    int add=1;
    while(!q.empty()){
        dp[now]=max(dp[now],q.top()+add);
        q.pop();
        add++;
    }

    return dp[now];
}

signed main(){
    int n;cin>>n;
    rep(i,1,n){
        int in;cin>>in;in--;
        v[in].pb(i);
    }

    cout<<dfs(0)<<endl;

}