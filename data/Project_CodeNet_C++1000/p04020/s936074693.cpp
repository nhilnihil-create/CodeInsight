#include <bits/stdc++.h>
using namespace std;
using ll=long long;
/*
1 2 2 2 9 3 0 4 8 9 
左にあわせてとりゃいいきがする
あれ、違った。
1 2 1
2
1 10 10 10 1
1 0 0 0 1になるか。だめだ
9 2 2 2 1
*/
int main(){
  ll N, ans=0; cin>>N;
  vector<ll> Z(N,0);
  for(int i=0; i<N; i++){
    ll A; cin>>A;
    Z[i]=A;
  }
  for(int i=0; i<N-1; i++){
    if(Z[i]<=Z[i+1]){
      ans+=Z[i];
      Z[i+1]-=Z[i];
      Z[i]=0;
    }
    else if(Z[i]>Z[i+1]){
      ans+=Z[i]/2;
      if(Z[i]%2==1){
        Z[i]=1;
        if(Z[i+1]>=1){
          ans++;
          Z[i]=0;
          Z[i+1]--;
        }
      }
      else Z[i]=0;
    }
//    cout<<"i:"<<i<<" ans:"<<ans<<endl;
  }
  ans+=Z[N-1]/2;
  cout<<ans<<endl;
}