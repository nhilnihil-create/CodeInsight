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
  vector<int> p(n);
  rep(i, n) cin >> p.at(i);
  rep(i, n) p.at(i)--;
  vector<int> a(n), b(n);
  rep(i, n){
    int no = (i+1) * (n+1);
    a.at(i) = b.at(n-i-1) = no;
  }
  rep(i, n){
    a.at(p.at(i)) += i;
  }
  rep(i, n){
    if(i != 0) cout << " ";
    cout << a.at(i);
  }
  cout << endl;
  rep(i, n){
    if(i != 0) cout << " ";
    cout << b.at(i);
  }
  cout << endl;
  return 0;
}