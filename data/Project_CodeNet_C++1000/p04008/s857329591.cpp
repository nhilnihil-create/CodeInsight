#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<tuple>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define Per(i,sta,n) for(int i=n-1;i>=sta;i--)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;

int n,k,ans=0;
vector<int> G[100010];
int p[100010],d[100010];

int dfs(int s){
  int res=0;
  for(int t:G[s]){
    d[t]=dfs(t);
    res=max(res,d[t]+1);
  }
  if(res>=k-1 && p[s]!=0) {
    ans+=1;
    res=-1;
  }
  //cout << s << " " << res << endl;
  return res;
}

void solve(){
  cin >> n >> k;
  p[0]=0;
  rep(i,n){
    int a;cin >> a;a--;
    if(i==0) {
      if(a!=0) ans+=1;
    }
    else{
      G[a].push_back(i);
      p[i]=a;
    }
  }
  dfs(0);
  cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(50);
    solve();
}