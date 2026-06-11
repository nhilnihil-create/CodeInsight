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

//-------------------------------------------------------------------
int M=1;
std::vector<int> seg;
void init(int N){
  while(M<N) M*=2;
  M=M*2-1;
  for(int i=0;i<M;i++) {
    seg.push_back(0);
  }
}
void update(int l, int r, int k){
  k+=(M+1)/2-1;
  seg[k]++;
  while(k>0){
    k = (k-1)/2;
    seg[k]++;
  }
}
ll query(int a, int b, int l, int r, int k){
  if(r<=a || b<=l) return 0;
  if(a<=l && r<=b) return seg[k];
  ll A = query(a, b, l, (l+r)/2, k*2+1);
  ll B = query(a, b, (l+r)/2, r, k*2+2);
  return A + B;
}
//-------------------------------------------------------------------

int main(int argc, char const *argv[]) {
  ll N, K, ans = 0;
  std::cin >> N >> K;
  std::vector<ll> A(N), S(N);
  init(N+1);
  for(int i=0;i<N;i++) {
    std::cin >> A[i];
    A[i]-=K;
  }
  set<ll> tmp;
  map<ll, ll> num;
  tmp.insert(0);
  for(int i=0;i<N;i++){
    S[i] = (i==0?0:S[i-1]) + A[i];
    if(tmp.find(S[i])==tmp.end()) tmp.insert(S[i]);
  }
  int c = 0;
  for(auto itr=tmp.begin();itr!=tmp.end();itr++, c++) {
    //std::cout << *itr << '\n';
    num.emplace(*itr, c);
  }
  update(0, (M+1)/2, num.at(0));
  for(int i=0;i<N;i++){
    ans += query(0, num.at(S[i])+1, 0, (M+1)/2, 0);
    update(0, (M+1)/2, num.at(S[i]));
  }
  std::cout << ans << '\n';
  return 0;
}
