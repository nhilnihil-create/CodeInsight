#include <bits/stdc++.h>
#define ll long long
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)

using namespace std;

int main() {
  int h, w;
  string result;
  cin >> h >> w;
  REP(i, h)
  {
    string c;
    cin >> c;

    result += c + "\n" + c + "\n";
  }

  cout << result;

  return(0);
}
