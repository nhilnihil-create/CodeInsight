#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  string S; cin >> S;
  string C = "CODEFESTIVAL2016";
  int cnt = 0;

  rep(i,S.length()) {
    if (S[i] != C[i]) cnt++;
  }
  
  cout << cnt << endl;
  return 0;
}