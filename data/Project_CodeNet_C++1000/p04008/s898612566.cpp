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

int a[100000];
vector<int> b[100000];
int ans=0;
int n,m;

int dfs(int now,int prev){
  int num=1;
  rep(i,b[now].size() ){
    num=max(num,dfs(b[now][i],now));
  }
  if(num==m && prev!=0){
    ans++;
    //cout<<now<<"! "<<1<<endl;
    return 1;
  }
  else{
    //cout<<now<<" "<<num<<endl;
    return num+1;
  }
}
    


signed main(){
  cin.tie(0);	
  ios::sync_with_stdio(false);
  
  cin>>n>>m;
  
  //int ans=0;
  
  rep(i,n){
    cin>>a[i];a[i]--;
    if(i!=0) b[a[i]].push_back(i);
  }
  if(a[0]!=0) ans++;
  dfs(0,0);
  //cout<<dfs(0)<<endl;
  cout<<ans<<endl;
  
  
  
  
  return 0;
}
