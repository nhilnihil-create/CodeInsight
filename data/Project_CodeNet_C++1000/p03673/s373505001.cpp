#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
  int n;
  std::cin >> n;
  deque<ll> dq;

  bool dir=true;

  rep(i,n){
    ll now;
    std::cin >> now;
    if(i%2==0)dq.push_back(now);
    else dq.push_front(now);
  }

  if(n%2==1)reverse(dq.begin(),dq.end());

  for(ll i:dq)std::cout << i<<' ';
  std::cout << "" << '\n';

  return 0;
}
