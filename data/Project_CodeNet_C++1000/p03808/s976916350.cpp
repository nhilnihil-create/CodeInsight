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
  ll N, sa=0;
  bool flag = true;
  std::cin >> N;
  std::vector<int> A(N);
  for(int i=0;i<N;i++) {
    std::cin >> A[i];
    sa += A[i];
  }
  ll time = (N*(N+1))/2;
  if(sa%time!=0) flag = false;
  ll k = sa/time;
  //std::cout << k << '\n';
  ll count=0;
  for(int i=0;i<N;i++){
    ll a = (A[i]-(i==0?A[N-1]:A[i-1]));
    ll b = (i==0?A[N-1]:A[i-1])-A[i] + k;
    if(a!=k && (b%N!=0 || b<=0)) flag = false;
    else if(b%N==0 && b>0)count+=b/N;
  }
  //std::cout << count << " " << k << '\n';
  std::cout << (flag&&count==k?"YES":"NO") << '\n';
  return 0;
}
