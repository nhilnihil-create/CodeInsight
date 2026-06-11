#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)


int main() {
  int N,M,R;
  cin >> N>>M>>R;
  vector<int>r(R);
  rep(i,R){
    cin>>r.at(i);
    r.at(i)--;
  }
  vector<int>a(M),b(M),c(M);
  rep(i,M){
    cin>>a.at(i)>>b.at(i)>>c.at(i);
    a.at(i)--;
    b.at(i)--;
  }
  vector<vector<int>>dist(N,vector<int>(N));
  rep(i,N) {
      rep(j,N) {
        dist[i][j]=1001001001;
      }
  }
  rep(i,N){
    dist[i][i]=0;
  }
  rep(i,M){
    dist[a.at(i)][b.at(i)]=c.at(i);
    dist[b.at(i)][a.at(i)]=c.at(i);
  }
  rep(k,N){
    rep(i,N) {
      rep(j,N) {
        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
      }
    }
  }
  int ans=1001001001;
  
  sort(r.begin(), r.end());
  do {
    int an=0;
    rep(i,r.size()-1){
      an+=dist[r.at(i)][r.at(i+1)];
    }
    ans=min(ans,an);
  } while (next_permutation(r.begin(), r.end()));

  cout<<ans<<endl;
}


