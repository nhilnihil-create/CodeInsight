#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;

ll calc(string s) {
  int len = s.length();
  ll ret = stoll(s);
  for (int i = 1; i < len; i++) {
    ret += stoi(s.substr(0, i)) * pow(2, len - i - 1);
    ret += calc(s.substr(i, len - 1));
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