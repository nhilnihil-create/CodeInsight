#include<bits/stdc++.h>
using namespace std;

const long long INF=1LL<<60;

long long dist[210][210];

int main(){
  int N,M,R;
  cin >> N >> M >> R;
  vector<int> r(R);
  for(int i=0;i<R;++i){
    cin >> r[i];
    r[i]--;
  }
  for(int i=0;i<210;++i){
    for(int j=0;j<210;++j){
      dist[i][j]=INF;
    }
    dist[i][i]=0;
  }
  vector<int> a(M),b(M),c(M);
  for(int i=0;i<M;++i){
    cin >> a[i] >> b[i] >> c[i];
    a[i]--;
    b[i]--;
    dist[a[i]][b[i]]=c[i];
    dist[b[i]][a[i]]=c[i];
  }
  for(int k=0;k<N;++k){
    for(int i=0;i<N;++i){
      for(int j=0;j<N;++j){
        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
      }
    }
  }
  long long ans=INF;
  sort(r.begin(),r.end());
  do{
    long long cal=0;
    for(int i=1;i<R;++i) cal+=dist[r[i]][r[i-1]];
    ans=min(ans,cal);
  }while(next_permutation(r.begin(),r.end()));

  cout << ans << endl;
  return 0;

}
