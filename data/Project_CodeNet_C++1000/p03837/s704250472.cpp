#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)


int main() {
  int N,M;
  cin >>N>>M;
  vector<int>a(M),b(M),c(M);
  rep(i,M){
    cin>>a.at(i)>>b.at(i)>>c.at(i);
    a.at(i)--;
    b.at(i)--;
  }
  vector<vector<int>>d(N,vector<int>(N));
  rep(i,N){
    rep(j,N){
      if(i==j){
        d.at(i).at(j)=0;
      }
      else{
        d.at(i).at(j)=1001001001;
      }
    }
  }
  rep(i,M){
    d.at(a.at(i)).at(b.at(i))=c.at(i);
    d.at(b.at(i)).at(a.at(i))=c.at(i);
  }
  
  
  
  for(int k = 0; k < N; k++) {
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {        
        d[i][j] =min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
 
  int ans=M;
  rep(i,M){
    bool ex=false;
    rep(j,N){
      if(d.at(j).at(a.at(i))+c.at(i)==d.at(j).at(b.at(i))){
        ex=true;
      }
    }
    if(ex){
      ans--;
    }
    
  }
  cout<<ans<<endl;
  
}