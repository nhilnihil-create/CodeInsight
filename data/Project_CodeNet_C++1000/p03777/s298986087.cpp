#include <bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i<n;++i)
using ll = long long;
using P = pair<int,int>;

int main(){
  string a,b;
  cin >> a >> b;
  if(a == "H" && b == "H") puts("H");
  if(a == "D" && b == "D") puts("H");
  if(a == "H" && b == "D") puts("D");
  if(a == "D" && b == "H") puts("D");
  return 0;
}
