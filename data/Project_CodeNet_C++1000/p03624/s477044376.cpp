#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  string s;
  cin >> s;
 
  bool app[26];
  for (int i = 0; i < 26; ++i) {
    app[i] = false;
  }
  int n = s.size();
  for (int i = 0; i < n; i++) {
	app[s[i] - 'a'] = true;
  }
  for (int i = 0; i < 26; ++i) {
    if (!app[i]){
      cout << (char)(i + 'a') << endl;
      return 0;
	}
  }
  cout << "None" << endl;
}