#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
ll N,K;
cin>>N>>K;
vector<ll> vec(N);
for(ll i=0;i<N;i++) {
  cin>>vec[i];
}
sort(all(vec));
reverse(all(vec));
ll ans=0;
for(ll i=0;i<K;i++) {
  ans+=vec[i];
}

cout<<ans<<endl;
}