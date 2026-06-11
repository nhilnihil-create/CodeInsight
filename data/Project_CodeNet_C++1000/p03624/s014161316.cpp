#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;
typedef vector<int> vi;

int main() {
  string s;
  cin >> s;

  bool d[26] = {false};

  for(int i=0; s[i] != '\0'; ++i) {
    d[s[i] - 'a'] = true;
  }
  for(int i=0; i < 26; ++i) {
    if (!d[i]) {
      printf("%c\n", (char)(i + 'a'));
      return 0;
    }
  }

  cout << "None" << endl;
  return 0;
}