#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int) n; i++)
using ll = long long;
template <class T>
using vt = std::vector<T>;
using vvi = std::vector<vt<int>>;

int main(){
  int a,b,c;
  std::cin >> a >> b >> c;

  ll t = a+b+c;
  int mini = std::min({a,b,c});
  int maxi = std::max({a,b,c});
  int mid = t - mini - maxi;

  if(t%2 == 0)
    std::cout << 0 << '\n';

  else
    std::cout << (ll)mini*mid << '\n';
  return 0;
}
