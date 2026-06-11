#include <bits/stdc++.h>
#include <vector> 
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

#define int long long
using namespace std;
const int MX = 1e6;
const int inf = 1e9;
const int mod = 1e9+7;
#define ll long long
signed main() {
  int n;
  cin >> n;
  int a;
  deque<int> dq;
  rep(i,n) {
    cin>> a;
    if(i%2==0) dq.push_back(a);
    else dq.push_front(a);
  }

  if(n%2==0) rep(i,n) cout << dq[i] <<" " << flush;
  else rrep(i,n) cout << dq[i] <<" " << flush;
  cout << "" << endl;


  return 0;
}
