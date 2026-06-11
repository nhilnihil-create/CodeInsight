#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
int INF = 1000000009;
int main()
{
  string s1,s2,s3;
  cin >> s1 >> s2 >> s3;
  string s;
  s += char(s1[0] - 32);
  s += char(s2[0] - 32);
  s += char(s3[0] - 32);
  cout << s << endl;
}