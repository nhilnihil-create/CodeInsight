#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
int main(){
  std::vector<ll> v(3);
  rep(i,3)std::cin >> v[i];
  sort(v.begin(),v.end());

  ll S=v[0]*v[1];

  ll mi=S*(v[2]/2+1);
  ll ma=S*(v[2]/2);


  if(v[0]%2==0 || v[1]%2==0 || v[2]%2==0)std::cout << "0" << '\n';
  else std::cout << mi-ma << '\n';


  return 0;
}
