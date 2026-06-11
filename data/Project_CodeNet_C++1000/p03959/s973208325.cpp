#include <bits/stdc++.h>
using namespace std;
using ll=unsigned long long;
/*
1以上、条件以下の組み合わせの積を出せばいい
もうだめ。。。なにが違うのかわからない。
ああ、末端で上昇したときが判定できてない
もおお7WAだよおおお
統括する
*/
int main(){
  ll N,MOD=1e9+7,ans=1; cin>>N;
  vector<ll> T(N+2,0), A(N+2,0);
  for(int i=1; i<=N; i++) cin>>T[i];
  for(int i=1; i<=N; i++) cin>>A[i];
  for(int i=1; i<=N; i++){//Tが上がったら確定。それ以下だったらNG
    if((T[i-1]<T[i] && T[i]>A[i]) || (A[i]>A[i+1] && T[i]<A[i])) ans=0;
    if(T[i-1]==T[i] && A[i]==A[i+1])
      (ans*=min(T[i], A[i]))%=MOD;
  }
  cout<<ans<<endl;
}
