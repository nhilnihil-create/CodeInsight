#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
const long long INF=1e9+5;
typedef long long ll;

int main() {
  ll K,S;
  cin>>K>>S;
  ll ans=0;
  for(int i=0;i<=K;i++){
    for(int j=0;j<=K;j++){
      int z=S-i-j;
      if(z>=0&&z<=K){
        ans++;
      }
    }
  }
  cout<<ans<<endl;
}