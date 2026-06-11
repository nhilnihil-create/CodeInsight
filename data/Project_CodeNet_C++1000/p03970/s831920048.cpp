#include<bits/stdc++.h>
#define REP(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
const ll MOD = 1000000007;

int main() {
  int c = 0;
  string s, cs = "CODEFESTIVAL2016";
  cin >> s;
  REP(i, cs.length()) if (s[i] != cs[i]) c++;
  cout << c << endl;
  return 0;
}