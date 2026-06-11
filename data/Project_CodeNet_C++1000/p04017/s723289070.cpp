#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_io ios::sync_with_stdio(0); cin.tie(0)
#define infl 1e18+9
#define inf 1e9+9
#define sz(a) ((int)a.size())
#define all(a) a.begin(),a.end()

const int mod=1e9+7; 
const int nax=1e5+5; 
int dp[20][nax]; 

void solve(){
  int n;  cin>>n; 
  vector<int> x(n); for(int i=0;i<n;i++) cin>>x[i]; 
  int l,q; cin>>l>>q; 
  for(int i=0;i<n;i++){
    int j=upper_bound(all(x),x[i]+l)-x.begin(); 
    dp[0][i]=j-1; 
  }
  for(int i=1;i<20;i++){
    for(int j=0;j<n;j++){
      dp[i][j]=dp[i-1][dp[i-1][j]]; 
    }
  }
  for(int i=0;i<q;i++){
    int a,b; cin>>a>>b;  a--; b--; 
    if(a>b) swap(a,b); 
    int ans=0,j=19; 
    while(j>=0){
      if(dp[j][a]<b){
        ans^=(1<<j); 
        a=dp[j][a]; 
      }
      j--; 
    }
    cout<<ans+1<<endl; 
  }
}

int main()
{
	fast_io;
	clock_t beg=clock(); 
	solve(); 
	clock_t end=clock(); 
	fprintf(stderr,"%.2lf sec\n",(double)(end-beg)/CLOCKS_PER_SEC); 
	return 0;
}