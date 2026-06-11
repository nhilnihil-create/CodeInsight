// includes {{{
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<tuple>
#include<cmath>
#include<random>
#include<cassert>
#include<bitset>
#include<cstdlib>
// #include<deque>
// #include<multiset>
// #include<cstring>
// #include<bits/stdc++.h>
// }}}
using namespace std;
using ll = long long;

int main() {
  std::ios::sync_with_stdio(false), std::cin.tie(0);
  ll k;
  cin >> k;
  
  vector<ll> v(50, 49 + k / 50);

  for(int i = 0; i < k % 50; i++) {
    for(int j = 0; j < 50; j++) {
      if(j == i) v[i] += 50;
      else v[j]--;
    }
  }

  cout << 50 << endl;
  for(int i = 0; i < 50; i++) cout << v[i] << " \n"[i == 50 - 1];
  return 0;
}
