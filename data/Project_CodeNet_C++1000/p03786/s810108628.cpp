#include <bits/stdc++.h>
using namespace std;
using ll=long long;
/*
1e5。
全通りは試せない
sortして累積和で比較
40 1 30 2 7 20
1 2 7 20 30 40
1 3 10 30 60 100
越えられない壁3-7があれば、それ以下は死亡
*/
int main(){
  ll N; cin>>N;
  vector<ll> A(N+1,0), B(N+1,0);
  for(int i=1; i<=N; i++){
    ll a; cin>>a;
    A[i]=a;
  }
  sort(A.begin(), A.end());
  for(int i=1; i<=N; i++){
    B[i]=B[i-1]+A[i];
  }
  ll ans=1;
  for(int i=1; i<N; i++){//累積和の2倍が次のAに届くかどうか
    if (B[i]*2<A[i+1]) ans=1;
    else ans++;
  }
  cout<<ans<<endl;
}