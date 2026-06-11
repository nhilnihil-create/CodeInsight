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
  int N;
  cin >> N;
  vector<int> X(N+1, 0);
  for(int i=0;i<N;i++) std::cin >> X[i+1];
  int L, Q;
  std::cin >> L;
  vvi ne = vv(N+1, 0, 0, int);
  for(int i=1;i<=N;i++){
    int n = upper_bound(X.begin(), X.end(), X[i]+L) - X.begin();
    ne[i].push_back(n-1);
  }
  bool flag = true;
  while(flag){
    flag = false;
    for(int i=1;i<=N;i++){
      int t = ne[i].size()-1;
      if(ne[i][t]!=N) {
        flag = true;
        int k = ne[i][t];
        ne[i].push_back(ne[k][ne[k].size()-1]);
      }
    }
  }
  /*
  for(int i=1;i<=N;i++){
    for(int j=0;j<ne[i].size();j++) std::cout << ne[i][j] << " ";
    std::cout << '\n';
  }
  */
  std::cin >> Q;
  int a, b;
  std::vector<int> T(64, 1);
  for(int i=1;i<64;i++) T[i] = T[i-1] * 2;
  for(int i=0;i<Q;i++){
    int ans = 0;
    std::cin >> a >> b;
    if(a>b) swap(a, b);
    while(a!=b){
      if(ne[a][0]>=b){
        ans++;
        break;
      }
      auto itr = upper_bound(ne[a].begin(), ne[a].end(), b);
      itr--;
      if(b==N) itr--;
      ans+=T[itr-ne[a].begin()];
      a = *itr;
    }
    std::cout << ans << '\n';
  }
  return 0;
}
