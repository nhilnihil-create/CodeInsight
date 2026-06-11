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
  int N, x;
  std::cin >> N;
  std::vector<int> A(N+1), B(N+1), p(N+1);
  for(int i=1;i<=N;i++) {
    std::cin >> x;
    p[x] = i;
  }
  for(int i=1;i<=N;i++){
    A[i] = i * 30000;
    B[i] = (N-i) * 30000 + p[i];
  }
  for(int i=1;i<=N;i++) std::cout << A[i] << (i==N?"\n":" ");
  for(int i=1;i<=N;i++) std::cout << B[i] << (i==N?"\n":" ");

  return 0;
}
