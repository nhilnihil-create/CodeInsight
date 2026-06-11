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
  vvi A = vv(N, 2, 0, int);
  set<int> num;
  std::vector<int> ans(N*N+1, 0);
  for(int i=0;i<N;i++) A[i][1]=i+1,std::cin >> A[i][0];
  sort(A.begin(), A.end());
  for(int i=1;i<=N*N;i++) num.insert(i);
  for(int i=0;i<N;i++) num.erase(A[i][0]), ans[A[i][0]]=A[i][1];
  for(int i=0;i<N;i++){
    for(int j=0;j<A[i][1]-1;j++){
      auto itr = num.begin();
      if(*itr>A[i][0]){
        std::cout << "No" << '\n';
        return 0;
      }
      ans[*itr] = A[i][1];
      num.erase(itr);
    }
  }
  for(int i=N-1;i>=0;i--){
    for(int j=0;j<N-A[i][1];j++){
      auto itr = num.end();
      itr--;
      if(*itr<A[i][0]){
        std::cout << "No" << '\n';
        return 0;
      }
      ans[*itr]=A[i][1];
      num.erase(*itr);
    }
  }
  std::cout << "Yes" << '\n';
  for(int i=1;i<=N*N;i++) std::cout << ans[i] << (i==N*N?"\n":" ");
  return 0;
}
