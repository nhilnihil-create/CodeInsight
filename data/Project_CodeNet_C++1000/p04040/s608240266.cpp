#include<bits/stdc++.h>

#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define ALL(a) (a).begin(),(a).end()
#define Yes(hoge) cout<<((hoge)?"Yes":"No")<<endl;
#define YES(hoge) cout<<((hoge)?"YES":"NO")<<endl;
using namespace std;
struct Grid{int x,y,t;};
struct Edge{int to,cost;};
struct Graph{vector<vector<Edge>>E;int V;
  const ll Inf = llINF;const int MAX_V=1010;vector<ll>d;
  Graph(int n):E(n){d.resize(MAX_V);E.resize(n);V=n;}
  void init(){for(int i=0;i<MAX_V;i++)d[i]=Inf;}
  void add_edge(int from,int to,int cost){E[from-1].pb({to-1,cost});}
};

ll mod_div(ll a,ll b){
  ll tmp=MOD-2,c=b,ret=1;
  while(tmp>0){
    if(tmp&1){
      ret*=c;ret%=MOD;
    }
    c*=c;c%=MOD;tmp>>=1;
  }
  return a*ret%MOD;
}
 
#define MAX_K 200100
vector<ll> kaijo(MAX_K);
ll combination(ll n, ll r){
  if(n<r||n<0||r<0)
    return 0;
  if(kaijo[0]!=1){
    kaijo[0]=1;
    for(ll i=1;i<MAX_K;i++)kaijo[i]=(kaijo[i-1]*i)%MOD;
  }
  ll ret=kaijo[n];
  long long tmp = (kaijo[r] * kaijo[n-r]) % MOD;
  return mod_div(ret,tmp);
}

void modadd(ll &a, ll b){
  a+=b;
  a%=MOD;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll h,w,a,b;cin>>h>>w>>a>>b;
  ll ans=0;
  for(ll i=b;i<w;i++){
    ans+=(combination(h-a-1+i,min(h-a-1,i))*combination(a-1+w-i-1,min(a-1,w-i-1)))%MOD;
    ans%=MOD;
  }
  cout<<ans<<endl;
  return 0;
}
