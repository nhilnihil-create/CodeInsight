#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<pll> vpl;
typedef vector<vll> vvll;

#define ALL(a) a.begin(),a.end()
#define SZ(a) ((int)a.size())
#define FI first
#define SE second
#define REP(i,n) for(int i=0;i<((int)n);i++)
#define REP1(i,n) for(int i=1;i<((int)n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define PB push_back
#define EB emplace_back
#define MP(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define yes cout<<"Yes"<<endl
#define YES cout<<"YES"<<endl
#define no cout<<"No"<<endl
#define NO cout<<"NO"<<endl
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL

const int inf = 1e9;
const ll linf = 1LL << 50;
const double eps = 1e-10;
const int MOD = 1e9 + 7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

const ll MAX_N=1e5+1;
vvll a(MAX_N);
vvll b(MAX_N);
vll memo(MAX_N,-1);

ll dfs(ll cur){
  if(a[cur].size()==0)
    return memo[cur]=0;

  if(memo[cur]>=0)
    return memo[cur];

  priority_queue<ll> que;
  for(auto g:a[cur]){
    que.push(dfs(g));
  }

  ll cnt=0;
  ll res=0;
  while(!que.empty()){
    res=max(res,cnt+que.top());
    que.pop();
    cnt++;
  }

  res++;
  memo[cur]=res;
  return res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin>>n;
  REP(i,n-1){
    ll x;
    cin>>x;
    x--;
    a[x].push_back(i+1);
  }

  ll ans=dfs(0);
  cout<<ans<<endl;
}

