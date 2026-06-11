#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  int n;
  cin >> n;
  deque<int> dq;
  rep(i, n){
    int a;
    cin >> a;
    if(i % 2 == 0) dq.push_back(a);
    else dq.push_front(a);
  }
  if(n % 2 == 0){
    while(!dq.empty()){
      cout << dq.front() << " ";
      dq.pop_front();
    }
    cout << endl;
  }else{
    while(!dq.empty()){
      cout << dq.back() << " ";
      dq.pop_back();
    }
    cout << endl;
  }
  return 0;
}