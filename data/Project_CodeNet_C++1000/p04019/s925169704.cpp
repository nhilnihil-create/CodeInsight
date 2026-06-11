#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;

  cin >> s;

  bool N = false, E = false, S = false, W = false;

  for (int i = 0; i < (int)s.size(); i++) {
    if (s.at(i) == 'N')
      N = true;
    else if (s.at(i) == 'W')
      W = true;
    else if (s.at(i) == 'S')
      S = true;
    else
      E = true;
  }

  if ((N && S && !W && !E) || (W && E && !N && !S) || (N && S && W && E))
    cout << "Yes";
  else
    cout << "No";

  return 0;
}