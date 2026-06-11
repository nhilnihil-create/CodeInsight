#include <bits/stdc++.h>
using namespace std;
using ll=long long;
//最大の下げ幅を見つける、それがいくつかを調べる。
//それだけコスト
//7 10 4 5 9 3 6 8 2 1
// 4-9
// 3-8
//おしりから見てくのがいいかな
//売値だけ
//10 10 9 9 9 8 8 8 2 1
//買値は？
//7  7  4 4 4 3 3 3 2 1
//あいことなる。

int main(){
  ll N,T; cin>>N>>T;
  vector<ll> A(N,0), sale(N,0), buy(N,0);
  for(int i=0; i<N; i++){
    ll a; cin>>a; A[i]=a;
  }
  ll tmp=0;
  for(int i=N-1; i>=0; i--) sale[i]=(tmp=max(tmp,A[i]));
  tmp=1e10;
  for(int i=0; i<N; i++) buy[i]=(tmp=min(tmp,A[i]));
  tmp=0;
  for(int i=0; i<N; i++) tmp=max(tmp,sale[i]-buy[i]);
  ll ans=0,s=0,b=0;
  for(int i=0; i<N; i++){
    if(sale[i]-buy[i]==tmp){
      if(s!=sale[i] || b!=buy[i]){
        ans++;
        s=sale[i];
        b=buy[i];
      }
    }
  }
  cout<<ans<<endl;
}