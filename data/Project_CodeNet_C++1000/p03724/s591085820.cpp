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
  int n, m;
  cin >> n >> m;
  vector<int> v(n, 0);
  rep(i, m){
    int a, b;
    cin >> a >> b;
    a--; b--;
    v.at(a)++; v.at(b)++;
  }
  rep(i, n){
    if(v.at(i) % 2 == 1){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}