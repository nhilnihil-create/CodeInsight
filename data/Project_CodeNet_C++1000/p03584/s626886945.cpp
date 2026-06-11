#include<bits/stdc++.h>
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define substr(s,f,t) (s.substr(f-1,t-f+1))
#define ALL(a) (a).begin(),(a).end()
#define Yes(hoge) cout<<((hoge)?"Yes":"No")<<endl;
#define YES(hoge) cout<<((hoge)?"YES":"NO")<<endl;
using namespace std;
struct Grid{ll x,y,t;};
struct Edge{ll to,cost;};
struct Graph{vector<vector<Edge>>E;int V;
  const ll Inf = llINF;const int MAX_V=201010;vector<ll>d;
  Graph(int n):E(n){d.resize(MAX_V);E.resize(n);V=n;}
  void init(){for(int i=0;i<MAX_V;i++)d[i]=Inf;}
  void add_edge(ll from,ll to,ll cost){E[from].pb({to,cost});}
};
void bits (ll a,ll fix){
  string s="";
  while(a>0){
    char c='0'+a%2;
    a/=2;
    s+=c;
  }
  for(int i=s.size();i<fix;i++)
    s+='0';
  reverse(s.begin(),s.end());
  cout<<s<<endl;
}


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,k;cin>>n>>k;
  vector<vector<pair<ll,ll>>> beki(35);
  vector<pair<ll,ll> > num(n);
  ll zero=0;
  for(int i=0;i<n;i++){
    cin>>num[i].F>>num[i].S;
    if(num[i].F==0)zero+=num[i].S;
    else
      for(int j=30;j>=0;j--){
	if((num[i].F)&(1<<j)){
	  beki[j].pb(num[i]);
	  break;
	}
      }
  }
  ll ans=0;
  ll keta=0;
  ll nu=k;
  while(nu>0){keta++;nu>>=1;}
  /*  ll bitsum=(1<<(keta-1));
  for(int i=0;i<keta-1;i++)
    for(int j=0;j<beki[i].size();j++){
      ans+=beki[i][j].S;
    }
  */
  ll bitsum=0;
  for(int i=keta-1;i>=0;i--){
    if(!((1<<i)&k))continue;
    ll sum=0;
    bitsum+=(1<<i);
    for(int j=0;j<keta;j++)
      for(int jj=0;jj<beki[j].size();jj++){
	if(beki[j][jj].F<(1<<i)){
	  sum+=beki[j][jj].S;
	  //  cout<<beki[j][jj].F<<" ! "<<bitsum<<endl;
	}else if(((beki[j][jj].F)|(bitsum-1)) == (bitsum-1)){
	  sum+=beki[j][jj].S;
	  //cout<<beki[j][jj].F<<" !! "<<(bitsum-(1<<i))<<endl;
	}
      }

    ll sum2=0;
    for(int j=0;j<keta;j++){
      for(int jj=0;jj<beki[j].size();jj++)
	if((bitsum|beki[j][jj].F)==bitsum)sum2+=beki[j][jj].S;
    }
    //cout<<sum<<" "<<ans<<" "<<sum2<<endl;
    ans=max(sum,max(ans,sum2));
  }
  cout<<ans+zero<<endl;
  return 0;
}
