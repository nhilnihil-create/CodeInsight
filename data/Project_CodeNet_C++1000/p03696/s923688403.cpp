#include <bits/stdc++.h>
using namespace std;
#define SORT(a) sort((a).begin(), (a).end())
#define RSORT(a) reverse((a).begin(), (a).end())
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
const long long INF = 1LL << 60;
// const int INF=1010101010;
using Graph = vector<vector<int>>;

int main() {
  int n;
  string s;
  cin >> n >> s;
  int cnt = 0;
  int cnt2 = 0;

  for (int i = 0; i < n; i++) {
    if (s[i] == '(')
      cnt++;
    else {
      if (cnt == 0)
        cnt2++;
      else
        cnt--;
    }
  }
  string res = "";
  for (int i = 0; i < cnt2; i++) res.push_back('(');
  res += s;
  for (int i = 0; i < cnt; i++) res.push_back(')');
  cout << res << endl;
}