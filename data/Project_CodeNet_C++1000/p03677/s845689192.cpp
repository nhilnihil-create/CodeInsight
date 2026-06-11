#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi std::vector<std::vector<int> >
#define vvl std::vector<std::vector<ll> >
#define MODs 1000000007;
typedef long long int ll;
using namespace std;

int main(int argc, char const *argv[]) {
  ll N, M, S=0;
  cin >> N >> M;
  vector<ll> A(N);
  multimap<ll, ll> mp;
  for(int i=0;i<N;i++) std::cin >> A[i];
  for(int i=1;i<N;i++){
    S+=A[i]-A[i-1] + (A[i]>A[i-1]?0:M);
    mp.emplace((A[i-1]==M-1?M:A[i-1]+1), 1);
    mp.emplace(A[i], -(A[i]-(A[i-1]+1)+M)%M);
  }
  ll now = 0, ma = 0, num = 0;
  for(int i=1;i<N;i++){
    ll a = A[i]-A[i-1]+(A[i]>A[i-1]?0:M);
    ll b = A[i];
    if(a >= b) ma += a - b, num++;
  }
  //std::cout << ma << " " << num << '\n';
  auto itr = mp.begin();
  for(int i=1;i<=M;i++){
    if(i!=1) now += num;
    else now = ma;
    ma = max(ma, now);
    //std::cout << now << " " << ma << '\n';
    while(itr!=mp.end()&&(*itr).first==i){
      if((*itr).second==1) num++;
      else now += (*itr).second, num--;
      itr++;
    }
  }
  std::cout << S - ma << '\n';
  return 0;
}
