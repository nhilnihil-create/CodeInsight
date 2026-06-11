#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#define vll vector<ll>
#define vvvl vector<vvl>
#define vvl vector<vector<ll>>
#define VV(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define VVV(a, b, c, d) vector<vvl>(a, vvl(b, vll (c, d)));
#define re(c, b) for(ll c=0;c<b;c++)
#define all(obj) (obj).begin(), (obj).end()
typedef long long int ll;
typedef long double ld;
using namespace std;

int main(int argc, char const *argv[]) {
  ll a,b;std::cin >> a >> b;
  if(a<=0&&b>=0) std::cout << "Zero" << '\n';
  else if(a>0) std::cout << "Positive" << '\n';
  else{
    // a<0 b<0
    ll num = b - a + 1;
    if(num%2==0) std::cout << "Positive" << '\n';
    else std::cout << "Negative" << '\n';
  }
  return 0;
}
