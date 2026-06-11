#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll N;
int main(){
  cin>>N;
  vector<ll>A(N);
  for(ll i=0;i<N;i++)
    cin>>A[i];
ll ans=0;
  for(ll i=0;i<N-1;i++){
  ans+=(A[i]/2);
    ll a=A[i]-2*(A[i]/2);
    if(a==1 && 1<=A[i+1]){
      A[i+1]--;ans++;
    }
  }ans+=(A[N-1]/2);
  cout<<ans<<endl;
  return 0;
}