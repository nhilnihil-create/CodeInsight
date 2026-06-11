#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF 1000000010
#define EPS 1e-9
#define fst first
#define scd second

#define debug(x) cout<<x<<endl;
#define repi(i,x,n) for(int i=x;i<n;i++)
#define rep(i,n) repi(i,0,n)
#define lp(i,n) repi(i,0,n)
#define repn(i,n) for(int i=n;i>=0;i--)
#define int long long
#define endl "\n"

bool comp(const pair<int,int> a,const pair<int,int> b){
  if(a.first > b.first) return true;
  else if(a.first < b.first) return false;
  else{
    if(a.second>b.second) return false;
    else return true;
  }
};


signed main(){
  cin.tie(0);	
  ios::sync_with_stdio(false);
  int n;
  cin>>n;
  int a[n];
  rep(i,n) cin>>a[i];
  int ans[n]={};
  vector<pair<int,int>> x;
  rep(i,n){
    x.push_back({a[i],i});
  }
  sort(x.begin(),x.end(),comp);
  int prevheight,nownum;
  prevheight=x[0].first;
  nownum=x[0].second;
  rep(i,x.size() ){
    if(prevheight!=x[i].first){
      ans[nownum]+=(prevheight-x[i].first)*i;
      prevheight=x[i].first;
      if(x[i].second < nownum) nownum=x[i].second;
    }
  }
  ans[nownum]+=prevheight*n;
  rep(i,n){
    cout<<ans[i]<<endl;
  }
      
  
  
  
    
  
    

  return 0;
}
