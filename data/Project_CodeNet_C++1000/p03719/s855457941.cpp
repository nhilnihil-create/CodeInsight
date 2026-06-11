#include <bits/stdc++.h>
using namespace std;
#define FOR(i, s, n) for (int i = (s); i < (n); i++)
#define rep(i, n) FOR(i, 0, n)

int main() {
  int a,b,c;cin>>a>>b>>c;
  bool ans = c >= a && c <= b;
  cout << (ans ? "Yes" : "No") << endl;
}
