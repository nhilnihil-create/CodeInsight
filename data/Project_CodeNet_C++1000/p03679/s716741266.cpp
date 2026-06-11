#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

int main(){
  int x, a, b;
  cin >> x >> a >> b;
  int add = a - b;
  if(add >= 0){
    cout << "delicious" << endl;
  }else{
    add *= -1;
    if(x < add){
      cout << "dangerous" << endl;
    }else{
      cout << "safe" << endl;
    }
  }
  return 0;
}