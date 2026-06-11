#include <bits/stdc++.h>
using namespace std;
#define FOR(i, s, n) for (int i = (s); i < (n); i++)
#define rep(i, n) FOR(i, 0, n)

int main() {
  int a,b;cin>>a>>b;
  int ans = (a%3)*(b%3)*((a+b)%3)==0;
  cout << (ans ? "Possible":"Impossible") << endl;
}
