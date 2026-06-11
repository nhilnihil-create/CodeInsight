#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  ll N;
  cin>>N;
  vector<ll> A(N);
  ll S=0;
  for(ll i=0;i<N;i++){
    cin>>A[i];
    S+=A[i];
  }
  if(S%(N*(N+1)/2)){
    cout<<"NO"<<endl;
    return 0;
  }
  S/=(N*(N+1)/2);
  for(int i=0;i<N;i++){
    ll a,b;
    if(i==N-1)
      a=A[i],b=A[0];
    else
      a=A[i],b=A[i+1];
    ll c=S-(b-a);
    if(c%N||c<0){
      cout<<"NO"<<endl;
      return 0;
    }
  }
  cout<<"YES"<<endl;
}