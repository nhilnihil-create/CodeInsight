#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;

int main(){
  string s;
  cin >> s;
  string ss = s;
  reverse(ss.begin(), ss.end());
  for (int i = 0; i < ss.size(); i++) {
    if (ss[i] == 'b') ss[i] = 'd';
    else if (ss[i] == 'd') ss[i] = 'b';
    else if (ss[i] == 'p') ss[i] = 'q';
    else if (ss[i] == 'q') ss[i] = 'p';
  }
  cout << (ss == s? "Yes" : "No") << endl;
  return 0;
}
