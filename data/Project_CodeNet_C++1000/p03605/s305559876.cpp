#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
using namespace std;

int main() {
  string n;
  cin >> n;
  bool flg = false;
  for(char x : n) {
    if(x == '9') flg = true;
  }
  
  if(flg) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
