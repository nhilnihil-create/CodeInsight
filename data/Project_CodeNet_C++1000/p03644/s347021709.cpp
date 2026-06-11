#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
ll N;
cin>>N;
ll ans=1;
while(ans<=N) {
  ans*=2;
}
ans/=2;
cout<<ans<<endl;
}