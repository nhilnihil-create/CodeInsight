#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  string ans = "";
  cin >> s;
  int N = s.size();
  for (int i=0; i < N; i++){
    if (i%2==0) ans = ans +s[i];
  }
  cout << ans << endl;
}
