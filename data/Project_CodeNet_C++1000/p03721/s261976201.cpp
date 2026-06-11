#include <bits/stdc++.h>
using namespace std;
using  ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

using namespace std;
int main(){
  ll n,k;
  std::cin >> n>>k;
  std::vector<ll> arr(100001,0);
  rep(i,n){
    int a,b;
    std::cin >> a>>b;
    arr[a]+=b;
  }

  ll now=0;
  rep(i,100001){
    now+=arr[i];
    if(now>=k){
      std::cout << i << '\n';
      return 0;
    }
  }



  return 0;
}
