#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ll N,M;
  cin>>N>>M;
  ll ans[N];
  for(ll &x:ans){
    x=0;
  }
  for(int i=0;i<M;i++){
    ll a,b;
    cin>>a>>b;
    a--;b--;
    ans[a]++;ans[b]++;
  }
  ll c=1;
  for(int i=0;i<N;i++){
    if(ans[i]%2){
      c=0;break;
    }
  }
  if(c){
    cout<<"YES";
  }
  else{
    cout<<"NO";
  }
}