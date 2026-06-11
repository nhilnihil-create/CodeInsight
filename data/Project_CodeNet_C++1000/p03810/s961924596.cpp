#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int solve(std::vector<int> &v) {
  if(v.size() == 1)
    return (v[0] - 1) % 2;
  else if(v.size() == 2)
    return (v[0] + v[1]) % 2;
  else {
    ll sum = 0;
    for(int i = 0; i < v.size(); i++)
      sum += v[i];
    if((sum - v.size()) % 2 == 1)
      return 1;
    int odds = 0, pos = 0;
    for(int i = 0; i < v.size(); i++){
      if(1 == v[i])
        return 0;
      else if(v[i] % 2 == 1){
        odds++;
        pos = i;
      }
    }
    if(odds == 1) {
      v[pos]--;
      int gcd = 0;
      for(int i = 0; i < v.size(); i++)
        gcd = std::__gcd(gcd, v[i]);
      for(int i = 0; i < v.size(); i++)
        v[i] /= gcd;
      return !solve(v);
    } else
      return 0;
  }
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> v(n);
  for(int i = 0; i < n; i++)
    std::cin >> v[i];
  int verdict = solve(v);
  if(verdict == 0)
    std::cout << "Second";
  else
    std::cout << "First";
}
