#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int) n; i++)
using ll = long long;
template <class T>
using vt = std::vector<T>;
using vvi = std::vector<vt<int>>;

int main(){
  int q,h,s,d,n;
  std::cin >> q >> h >> s >> d >> n;

  int q_1 = 4*q, h_1 = 2*h, qh_1 = 2*q + h;

  int two = n/2;
  int one = n%2;

  int min = std::min({q_1, h_1, qh_1, s});
  if(two == 0)
    std::cout << min << '\n';
  else
    std::cout << (ll) std::min(min*2,d)*two + min*one << '\n';
  return 0;
}
