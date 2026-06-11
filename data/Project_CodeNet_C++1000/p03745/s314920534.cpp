#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int) n; i++)
using ll = long long;
template <class T>
using vt = std::vector<T>;
using vvi = std::vector<vt<int>>;

int main(){
  int n, cnt = 1;
  bool up = false, down = false;
  std::cin >> n;
  rep(i,n){
    ll a, tmp;
    std::cin >> a;
    if(i == 0){
      tmp = a;
      continue;
    }
    if(a > tmp) up = true;
    else if(tmp > a) down = true;
    if(up && down){
      cnt++;
      up = false; down = false;
    }
    tmp = a;
  }

  std::cout << cnt << '\n';
  return 0;
}
