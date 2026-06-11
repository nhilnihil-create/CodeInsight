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
  ll N, A, B, C, D;
  std::cin >>  N >> A >> B >> C >> D;
  for(int m=0;m<N;m++){
    if(C*(N-1-m)-D*m<=B-A&&B-A<=-C*m+D*(N-1-m)){
      std::cout << "YES" << '\n';
      return 0;
    }else if(m==N-1) std::cout << "NO" << '\n';
  }
  return 0;
}
