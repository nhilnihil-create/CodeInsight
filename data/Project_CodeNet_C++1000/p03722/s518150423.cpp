#include<bits/stdc++.h>
using namespace std;
//<<setprecision(20)

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 1000000000000
#define MOD 1000000007
using ll = long long;
using Graph = vector<vector<int>>;

int main(){
  //頂点数と辺数
  int N,M; cin>>N>>M;
  //グラフ情報
  vector<ll> A(M),B(M),C(M);
  rep(i,M){
    cin>>A.at(i)>>B.at(i)>>C.at(i);
    C.at(i)*=(-1);
}
  //視点からの距離
  vector<ll> dist(N,INF);
  //初期化
  dist.at(0)=0;

  for(int loop = 1; loop <= N-1; loop++){
    for(int i = 0; i < M; i++){
      if(dist.at(A.at(i)-1)==INF)continue;
      dist.at(B.at(i)-1)=min(dist.at(A.at(i)-1)+C.at(i),dist.at(B.at(i)-1));
    }
  }

  ll ans = -dist.at(N-1);
  //cout<<ans<<endl;

  //負の閉路の検出
  vector<bool> NC(N,false);//negative cycle

  for(int loop = 1; loop <= N; loop++){
    for(int i = 0; i < M; i++){
      if(dist.at(A.at(i)-1)==INF)continue;
      if(dist.at(B.at(i)-1)>dist.at(A.at(i)-1)+C.at(i)){
        dist.at(B.at(i)-1)=dist.at(A.at(i)-1)+C.at(i);
        NC.at(B.at(i)-1)=true;
      }
      if(NC.at(A.at(i)-1)==true)NC.at(B.at(i)-1)=true;
    }
  }

  if(NC.at(N-1))cout<<"inf"<<endl;
  else cout<<ans<<endl;
    
  return 0;
}