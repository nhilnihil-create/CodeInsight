#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N;
  cin>>N;
  string S;
  cin>>S;
  ll ans=0;
  ll ma=0;
  for(ll i=0;i<N;i++) {
if(S[i]=='I') {
ans++;
}
if(S[i]=='D') {
ans--;
}
    ma=max(ans,ma);
  }
  
  cout<<ma<<endl;
}
