#include <bits/stdc++.h>
using namespace std;

const int INF = 1001001001;

int main() {
string s;
cin >> s;
long long ans = 0;
for (int tmp = 0; tmp < (1 << s.size()-1); tmp++) {
  string ka;
  ka.push_back(s.at(0));
  bitset<10> bt(tmp);
  for (int i = 0;i < s.size() - 1;i++) {
    if (bt.test(i)) {
      ans += stoll(ka);
      ka = '0';
      ka.push_back(s.at(i+1));
    } else {
      ka.push_back(s.at(i+1));
    }
  }
  ans += stoll(ka);
  }

cout << ans << endl;



return 0;
}