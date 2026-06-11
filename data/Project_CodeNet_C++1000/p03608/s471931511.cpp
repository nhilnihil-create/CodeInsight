#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) begin(x), end(x)
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
typedef pair <int,int> P;

int main(){
  int V,M,R;
  cin>>V>>M>>R;
  int r[10];
  rep(i,R){
    cin>>r[i];
    r[i]--;
  }
  const int MAX_V=205;
  int d[MAX_V][MAX_V];
  rep(i,V) rep(j,V) {
    d[i][j]=1e9;
    if (i==j) d[i][j]=0;
  }
  rep(i,M){
    int a,b,c;
    cin>>a>>b>>c;
    a--; b--;
    d[a][b]=c;
    d[b][a]=c;
  }

  for (int k=0; k<V; k++) {
    for (int i=0; i<V; i++) {
      for (int j=0; j<V; j++) {
	d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
      }
    }
  }
  sort(r,r+R);
  int ans=1e9;
  do{
    int sum=0;
    bool f=true;
    rep(i,R-1){
      int p1=r[i],p2=r[i+1];
      if(d[p1][p2]==1e9){
	f=false;
	break;
      }
      sum+=d[p1][p2];
    }
    if(f) chmin(ans,sum);
  }while(next_permutation(r,r+R));
  cout<<ans<<endl;
  return 0;
}
