#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = a; i < b; i++)
#define re(i, n) fo(i, 0, n)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
int main()
{
  string s;
  cin >> s;

  string t = "";
  re(i, s.size()) {
    if (i % 2 == 0) t += s[i];
  }

  cout << t << endl;

  return 0;
}
