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
  ll w,h;cin>>w>>h;
  vector<ll>width(w),height(h);
  for(int i=0;i<w;i++)
    cin>>width[i];
  for(int j=0;j<h;j++)
    cin>>height[j];
  sort(ALL(width));
  sort(ALL(height));
  ll wcnt=0,hcnt=0;
  ll ans=0;
  ll sum=0;
  while(sum<(h+1)*(w+1)-1){
    if((wcnt==w)||(hcnt!=h&&height[hcnt]<width[wcnt])){
      ans+=height[hcnt]*(min(w+1-wcnt,((h+1)*(w+1)-1)-sum));
      sum+=min(w+1-wcnt,((h+1)*(w+1)-1)-sum);
      hcnt++;
    }else{
      ans+=width[wcnt]*(min(h+1-hcnt,((h+1)*(w+1)-1)-sum));
      sum+=min(h+1-hcnt,((h+1)*(w+1)-1)-sum);
      wcnt++;
    }
    // cout<<sum<<" "<<ans<<" "<<hcnt<<" "<<wcnt<<endl;
  }
  cout<<ans<<endl;
  return 0;
}
