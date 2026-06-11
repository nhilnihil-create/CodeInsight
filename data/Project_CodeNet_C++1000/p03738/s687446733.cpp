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

const string G = "GREATER";
const string L = "LESS";
const string E = "EQUAL";

int main(){
  string a, b;
  cin >> a >> b;
  if(a.size() > b.size()) cout << G << endl;
  else if(a.size() < b.size()) cout << L << endl;
  else{
    if(a > b) cout << G << endl;
    else if(a < b) cout << L << endl;
    else cout << E << endl;
  }
  return 0;
}