#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  string s;
  int cnt = 0;
  int size = 0;
  cin >> s;
  size = s.size();
  cnt = size - 2;
  cout << s[0] << cnt << s[size - 1] << endl;
}
