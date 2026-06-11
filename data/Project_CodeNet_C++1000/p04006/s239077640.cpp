#include <bits/stdc++.h>
using namespace std;
using ll=long long;
/*
DPぽいがむずいな
1箇所生成して流す
2箇所生成して流す
3箇所生成して流す
とかのいずれ。
全探索？
流す回数で探索か？
どうせN回生成はする。
それぞれの箇所について、最小手を計算する？
5 100
100 16 39 199 2
100 16 39 139 2
作って流す、のコストと、その場で作る、と。
N*Nで間に合いそう
//それぞれの値について。
どこで生成したか、と
何回動かしたか。
違ったか。
一番コストの低いのが作ってまわす
2番目にコストも作ってまわす。
もしコストふえたらそこで終了？
そんなことないか
魔法回数固定して全探索
*/

int main(){
  ll N,x; cin>>N>>x;
  vector<ll> Z(N,0), minbox(N,1e9);
  for(int i=0; i<N; i++){
    ll a; cin>>a;
    Z[i]=a;
  }
  ll ans=1e14;
  for(int i=0; i<N; i++){//魔法回数
    ll cost=0;
    for(int j=0; j<N; j++){
      ll pos=(N+j-i)%N;//生成ポジション
      minbox[j]=min(minbox[j], Z[pos]);
      cost+=minbox[j];
    }
    cost+=i*x;
    ans=min(ans,cost);
  }
  cout<<ans<<endl;
}