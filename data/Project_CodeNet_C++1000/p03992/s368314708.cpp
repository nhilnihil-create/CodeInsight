#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

int main() {
  string s;
  cin >> s;
  for (int i = 0; i < 4; i++) {
    cout << s[i] << flush;
  }
  cout << " " << flush;
  for (int i = 4; i < s.size(); i++) {
    cout << s[i] << flush;
  }
  cout << endl;
  return 0;
}