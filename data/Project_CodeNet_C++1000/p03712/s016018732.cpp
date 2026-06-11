#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int h, w;
  cin >> h >> w;

  string str[h];

  rep(i, h)
  {
    cin >> str[i];
    str[i] = '#' + str[i] + '#';
  }

  rep(i, w+2)
  {
    cout << '#';
  }
  cout << endl;

  rep(i, h)
  {
    cout << str[i] << endl;
  }

  rep(i, w+2)
  {
    cout << '#';
  }
  cout << endl;

}
