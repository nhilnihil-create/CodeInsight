#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int N,M,R;
  cin>>N>>M>>R;
  int r[R];
  rep(i,0,R){
    cin>>r[i];
    r[i]--;
  }
  sort(r,r+R);
  int d[N][N];
  rep(i,0,N){
    rep(j,0,N){
      d[i][j]=20000000;
    }
  }
  rep(i,0,N){
    d[i][i]=0;
  }
  rep(i,0,M){
    int a,b,c;
    cin>>a>>b>>c;
    d[a-1][b-1]=c;
    d[b-1][a-1]=c;
  }
  
  rep(k,0,N){
    rep(i,0,N){
      rep(j,0,N){
        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
      }
    }
  }
  int ans=200000000;
  do{
    int cur=0;
    rep(i,0,R-1){
      cur+=d[r[i]][r[i+1]];
    }
    ans=min(ans,cur);
  } while(next_permutation(r,r+R));
  cout<<ans<<endl;
}