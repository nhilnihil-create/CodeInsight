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
  ll N, S = 0;;
  std::cin >> N;
  std::vector<ll> A(N+1);
  ll now = -1, idx = -1;
  for(int i=1;i<=N;i++) {
    std::cin >> A[i];
    S+=A[i];
    if(now<A[i]) now = A[i], idx = i;
  }
  multimap<ll, ll, greater<ll> > front;
  multiset<ll> back;
  ll eq = 1;
  for(int i=1;i<idx;i++) front.emplace(A[i], i);
  for(int i=idx+1;i<=N;i++){
    if(A[i]==A[idx]) eq++;
    else back.insert(A[i]);
  }
  std::vector<ll> ans(N+1, 0);
  while(idx!=1){
    while(true){
      if((*front.begin()).second>idx) {
        back.insert((*front.begin()).first);
        front.erase(front.begin());
      }else break;
    }
    ll next_num = (*front.begin()).first;
    ans[idx]+=eq*(A[idx]-next_num);
    while(true){
      auto itr = back.lower_bound(next_num);
      if(itr==back.end()) break;
      eq++,ans[idx]+=(*itr)-next_num;
      back.erase(itr);
    }
    eq++;
    idx = (*front.begin()).second;
    front.erase(front.begin());
  }
  for(int i=1;i<=N;i++) S-=ans[i];
  for(int i=1;i<=N;i++) std::cout << (i==1?S:ans[i]) << "\n";
  return 0;
}
