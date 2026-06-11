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

multimap<int, int> num;
int check(int now){
  auto itr = num.lower_bound(now);
  int count = 0;
  multiset<int> ans;
  while(itr!=num.end()&&(*itr).first==now){
    count++;
    ans.insert(check((*itr).second));
    itr++;
  }
  int ret = 0;
  auto it = ans.begin();
  for(int i=0;i<ans.size();i++){
    ret = max((*it)-i, ret);
    it++;
  }
  return count + ret;
}
int main(int argc, char const *argv[]) {
  int N, x;
  std::cin >> N;
  for(int i=2;i<=N;i++) {
    std::cin >> x;
    num.emplace(x, i);
  }
  std::cout << check(1) << '\n';
  return 0;
}
