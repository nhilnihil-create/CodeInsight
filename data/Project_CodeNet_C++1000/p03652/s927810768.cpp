#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
#define range(i, r) for(int i=0;i<r;i++)
#define ranges(i, l, r) for(int i=l;i<r;i++)
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi std::vector<std::vector<int> >
#define vvl std::vector<std::vector<ll> >
#define MODs 1000000007;
#define MODn 1000000009;
typedef long long int ll;
using namespace std;

int main(int argc, char const *argv[]) {
  int N, M, ans = 9999;
  std::cin >> N >> M;
  vvi A = vv(N, M, 0, int);
  range(i, N) range(j, M) std::cin >> A[i][j];
  std::vector<int> remove, ite(N, 0);

  while(remove.size()!=M){
    int reg = 0, mos = 0, num = 0;
    std::vector<int> count(M+1, 0);
    for(int i=0;i<N;i++) {
      while(find(remove.begin(), remove.end(), A[i][ite[i]])!=remove.end()){
        ite[i]++;
      }
      count[A[i][ite[i]]]++;
      if(mos<count[A[i][ite[i]]]){
        mos = count[A[i][ite[i]]];
        num = A[i][ite[i]];
      }
    }
    remove.push_back(num);
    for(int i=0;i<N;i++) {
      if(A[i][ite[i]]==num) {
        ite[i]++;
        reg++;
      }
    }
    ans = min(ans, reg);
  }
  std::cout << ans << '\n';
  return 0;
}
