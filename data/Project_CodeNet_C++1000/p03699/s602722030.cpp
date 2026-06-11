#include <bits/stdc++.h>
using namespace std;
using  ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

using namespace std;
int main(){
  int n;
  std::cin >> n;

  int ans=0;
  int m=1000;
  rep(i,n){
    int now;
    std::cin >> now;
    ans+=now;
    if(now%10!=0 && m>now)m=now;
  }

  if(ans%10==0 && m!=1000)std::cout << ans-m << '\n';
  else if(ans%10 !=0)std::cout << ans << '\n';
  else std::cout << 0 << '\n';



  return 0;
}
