#include <bits/stdc++.h>
using namespace std;

int kaijo(int N){
  int ans=1;
  for(int i=1;i<=N;i++){
    ans*=i;
  }
  return ans;
}

int main() {
  long N,M,R;
  cin>>N>>M>>R;
  vector<vector<long>> d(N,vector<long>(N));
  vector<long> r(R);
  for(int i=0;i<R;i++) cin>>r[i],r[i]--;
  for(int i=0;i<N;i++)for(int j=0;j<N;j++) if(i!=j) d[i][j]=1e18;
  for(int i=0;i<M;i++){
    long a,b,c;
    cin>>a>>b>>c;
    a--,b--;
    d[a][b]=c,d[b][a]=c;
  }

  for(int k=0;k<N;k++)for(int i=0;i<N;i++)for(int j=0;j<N;j++){
    d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
  }


  long ans=1e18;
  for(int i=0;i<kaijo(R+1);i++){
    long c=0;

    for(int j=0;j<R-1;j++){
      c+=d[r[j+1]][r[j]];
    }

    ans=min(ans,c);
    next_permutation(r.begin(),r.end());
  }
cout<<ans<<endl;
}
