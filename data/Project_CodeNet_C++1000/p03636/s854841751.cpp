#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;

int main() {
  string s;
  cin >> s;

  string num = to_string(s.size() - 2);

  cout << s[0] + num + s[s.size() - 1] << endl;
}