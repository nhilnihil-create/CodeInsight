#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int N,M;
  cin>>N>>M;
  vector<pair<int,int>> S(N);
  rep(i,N){
    int f,s;
    cin>>f>>s;
    S[i]=make_pair(f,s);
  }
  vector<pair<int,int>> C(M);
  rep(i,M){
    int f,s;
    cin>>f>>s;
    C[i]=make_pair(f,s);
  }
  rep(i,N){
    int ans=0,ne=9999999999999999;
    rep(j,M){
      int A=S[i].first,B=C[j].first,CC=S[i].second,D=C[j].second;
      int nex=abs(A-B)+abs(CC-D);
      if(ne>nex){
        ans=j+1;
        ne=nex;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}