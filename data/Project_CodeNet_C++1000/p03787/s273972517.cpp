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
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;

int n,m,c[100010];
vector<int> G[100010];

bool dfs(int s){
  bool res=true;
  for(int t:G[s]){
    if(c[t]!=-1){
      if(c[s]==c[t]) res=false;
    }
    else{
      c[t]=(c[s]+1)%2;
      if(!dfs(t)) res=false;
    }
  }
  return res;
}

void solve(){
  cin >> n >> m;
  rep(i,n) c[i]=-1;
  rep(i,m){
    int a,b;cin >> a >> b;
    a--;b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  ll p=0,q=0,r=0;
  rep(i,n){
    if(c[i]==-1){
      if(G[i].empty()) r+=1;
      else{
        bool f=dfs(i);
        if(f) p+=1;
        else q+=1;
      }
    }
  }
  //cout << p << " " << q << " " << r << endl;
  cout << p*p+(p+q)*(p+q)+2*r*(n-r)+r*r << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(50);
    solve();
}