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
  string S;
  std::cin >> S;
  int N = S.size();
  int a = 0, b = 0;
  if(N%2==0) a = 1;
  if(S[0]==S[N-1]) b = 1;
  std::cout << ((a^b)==1?"Second":"First") << '\n';
  return 0;
}
