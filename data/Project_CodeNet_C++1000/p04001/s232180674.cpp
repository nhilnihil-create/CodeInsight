#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll calc(string s)
{
  int len = s.length();
  ll ret = stoll(s);
  for (int i=1; i<len; i++) {
    string sl = s.substr(0, i);
    ret += stoll(sl) * pow(2, (len-i-1));
    string sr = s.substr(i, len-i);
    ret += calc(sr);
  }
  return ret;
}

int main()
{
  string s;
  cin >> s;
  cout << calc(s) << endl;

  return 0;
}
