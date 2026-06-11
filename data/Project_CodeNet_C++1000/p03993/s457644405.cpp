#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int) n; i++)
using ll = long long;
template <class T>
using vt = std::vector<T>;
using vvi = std::vector<vt<int>>;

int main(){
  int n,cnt = 0;
  std::cin >> n;
  vt<int> a(n,-1);

  rep(i,n) {
    int num;
    std::cin >> num;
    --num;
    a[i] = num;
    if(a[num] == i)
      cnt++;
  }
  std::cout << cnt << '\n';
  return 0;
}
