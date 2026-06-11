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
  Graph(int n):E(n){E.resize(n);V=n;}
  void add_edge(int from,int to,int cost){E[from-1].pb({to-1,cost});}
};
int main(){
  int n;cin>>n;
  ll ans=0;
  ll now=0;
  vector<ll>hoge;
  for(int i=0;i<n;i++){
    ll num;cin>>num;
    if(now+1==num){now++;hoge.pb(ans);continue;}
    if(num%(now+1)==0){
      ans+=num/(now+1)-1;
      now=max(now,1LL);
    }else{
      ans+=num/(now+1);
      now=max(now,1LL);
    }
    hoge.pb(ans);
  }
  /*for(int i=0;i<hoge.size();i++)
    cout<<hoge[i]<<" ";
    cout<<endl;*/
  cout<<ans<<endl;
  return 0;
}