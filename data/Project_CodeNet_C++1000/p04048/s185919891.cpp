#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi std::vector<std::vector<int> >
#define vvl std::vector<std::vector<ll> >
#define MODs 1000000007;
typedef long long int ll;
using namespace std;

int main(int argc, char const *argv[]) {
  ll N, X, ans = 0, a, b;
  std::cin >> N >> X;
  ans = N, a = X, b = N-X;
  while(true){
    if(a>b) swap(a, b);
    ans += 2*a*(b/a);
    //std::cout << a << " " << b << " " << ans << '\n';
    b = b % a;
    if(b==0) {
      ans -= a;
      break;
    }
  }
  std::cout << ans << '\n';
  return 0;
}
