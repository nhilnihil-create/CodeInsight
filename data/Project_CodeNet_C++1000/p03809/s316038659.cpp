#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define R cin>>
#define Z class
#define ll long long
#define ln cout<<'\n'
#define in(a) insert(a)
#define pb(a) push_back(a)
#define pd(a) printf("%.10f\n",a)
#define mem(a) memset(a,0,sizeof(a))
#define all(c) (c).begin(),(c).end()
#define iter(c) __typeof((c).begin())
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define REP(i,m,n) for(int i=(int)(m);i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)
#define tr(it,c) for(iter(c) it=(c).begin();it!=(c).end();it++)
template<Z A>void pr(A a){cout<<a;ln;}
template<Z A,Z B>void pr(A a,B b){cout<<a<<' ';pr(b);}
template<Z A,Z B,Z C>void pr(A a,B b,C c){cout<<a<<' ';pr(b,c);}
template<Z A,Z B,Z C,Z D>void pr(A a,B b,C c,D d){cout<<a<<' ';pr(b,c,d);}
template<Z A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}ln;}
ll check(ll n,ll m,ll x,ll y){return x>=0&&x<n&&y>=0&&y<m;}
const ll MAX=1000000007,MAXL=1LL<<61,dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
typedef pair<int,int> P;
ll n,a[111111];
vector<int> v[111111];

ll dfs(int x,int p) {
  ll cnt=0;
  bool f=0;
  rep(i,v[x].size()) {
    int y=v[x][i];
    if(y==p) continue;
    f=1;
    ll d=dfs(y,x);
    if(d>a[x]) return MAX;
    cnt+=d;
  }
  if(f) {
    if(a[x]>cnt||cnt>a[x]*2) return MAX;
    a[x]-=cnt-a[x];
  }
  return a[x];
}

void Main() {
  cin >> n;
  for(int i=0; i<n; i++) cin >> a[i];
  for(int i=0; i<n-1; i++) {
    int x,y;
    cin >> x >> y;
    x--,y--;
    v[x].pb(y);
    v[y].pb(x);
  }
  if(n==2) {
    if(a[0]==a[1]) pr("YES");
    else pr("NO");
    return;
  }
  rep(i,n) {
    if(v[i].size()==1) continue;
    if(!dfs(i,-1)) pr("YES");
    else pr("NO");
    return;
  }
}

int main(){ios::sync_with_stdio(0);cin.tie(0);Main();return 0;}
