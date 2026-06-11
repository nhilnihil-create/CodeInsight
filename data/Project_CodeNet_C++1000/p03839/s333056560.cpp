#include <bits/stdc++.h>
using namespace std;
using ll=long long;
/*
DPっぽいけど違うかな
しゃくとりか
和がマイナスになった時点で仕切りなおし、かな
-4 10 -11 300 -5 1  -20 500
0  10 -1　300    296                
いったん、プラスとマイナスは合算してよくて
プラスがきた場合、そのままか、これまでのプラスを引き継ぐか、で判断？
マイナスになったらリセットで。
ああ、連続するKます
ってことはシマシマとりも可能なわけか
どこかKマス続きが1箇所で、それ以外は任意の取得可能、か。
プラスの総和をだす。
そのあと、K並びを、とる場合ととらない場合とで、もっとも効率のいいものを選択
＋の配列と-の配列、それぞれで累積和用意。
とる場合、マイナスが少ないもの
とらない場合、プラスが少ないもの
が回答か
bwbbbとかbwwwbとか
*/
int main(){
  ll N,K; cin>>N>>K;
  vector<ll> P(N+1,0), M(N+1,0);
  for(int i=1; i<=N; i++){
    ll a; cin>>a;
    if(a>0)
      P[i]=a;
    else
      M[i]=a;
  }
  //累積和
  for(int i=1; i<=N; i++){
    P[i]=P[i-1]+P[i];
    M[i]=M[i-1]+M[i];
  }
  ll lose=1e14;
  for(int i=K; i<=N; i++){
    ll ptmp=P[i]-P[i-K];
    ll mtmp=M[i-K]-M[i];
    lose=min(lose, min(ptmp, mtmp));
  }
  ll ans=P[N]-lose;
  cout<<ans<<endl;
}