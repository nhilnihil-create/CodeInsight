#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

const int INF = 1001001001;

int main(){
  int mn10 = INF;
  int n;
  cin >> n;

  int sum = 0;
  rep(i, n){
    int in;
    cin >> in;
    sum += in;
    if(in % 10 != 0){
      mn10 = min(mn10, in);
    }
  }
  if(sum % 10 != 0) cout << sum << endl;
  else{
    if(mn10 == INF) cout << 0 << endl;
    else cout << sum-mn10 << endl;
  }
  return 0;
}