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
  ll I, O, T, J, L, S, Z;
  std::cin >> I >> O >> T >> J >> L >> S >> Z;
  ll length = O + (L/2)*2 + (J/2)*2 + (I/2)*2;
  if(L%2==1&&J%2==1&&I%2==1) length += 3;
  if(L>=1&&J>=1&&I>=1&&(L%2==0?1:0)+(J%2==0?1:0)+(I%2==0?1:0)==1) length += 1;
  std::cout << length << '\n';
  return 0;
}
