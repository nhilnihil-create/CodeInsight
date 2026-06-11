#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,string>;

int main() {
  int x,a,b;
  cin >> x>>a>> b;
  if(b<=a)cout << "delicious" << endl;
  else if(b <= a+x) cout << "safe" << endl;
  else cout << "dangerous" << endl;
  
  
}