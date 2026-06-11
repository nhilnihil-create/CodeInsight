#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  deque<int> deq;
  rep(i, n){
    if(i % 2 == 0) deq.push_back(a.at(i));
    else deq.push_front(a.at(i));
  }

  while(!deq.empty()){
    if(deq.size() != n){
      cout << " ";
    }
    if(n % 2 == 0){
      cout << deq.front();
      deq.pop_front();
    }else{
      cout << deq.back();
      deq.pop_back();
    }
  }
  cout << endl;
  return 0;
}