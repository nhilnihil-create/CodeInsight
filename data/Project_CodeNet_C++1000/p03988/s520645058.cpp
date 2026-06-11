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
  std::cin >> N;
  std::vector<int> A(N);
  for(int i=0;i<N;i++) std::cin >> A[i];
  sort(A.begin(), A.end());
  bool flag = true;
  int now = A[0], count=1;
  for(int i=1;i<N;i++) {
    if(A[i]-A[i-1]>=2) flag = false;
    if(A[i]==A[i-1])count++;
    else if(now!=A[0]&&count<2) flag = false;
    now = A[i];
  }
  if(N>=3 && A[0]==A[2]) flag = false;
  if(A[0]==A[1] && A[N-1]%2!=1) flag = false;
  if(A[0]!=A[1] && A[N-1]%2!=0) flag = false;
  std::cout << (flag?"Possible":"Impossible") << '\n';
  return 0;
}
