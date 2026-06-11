// https://atcoder.jp/contests/abc043/tasks/abc043_a
#include <iostream>

#define toDigit(c) (c-'0')
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define _ std::ios::sync_with_stdio(false); std::cin.tie(0);
#define debug(x) std::cout << '>' << #x << ':' << x << std::endl;

typedef long long LL;

int main() { _
  int n;
  std::cin >> n;

  int acc = 0;
  for(int i=1; i<=n; i++)
    acc += i;

  std::cout << acc << '\n';

  return 0;
}
