#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = s; i < (int)(n); i++)
typedef long long ll;

int main() {
  string s;cin >> s;
  rep(i,4)cout << s[i];
  cout << ' ';
  rep2(i,4,12)cout << s[i];
  cout << endl;
}
