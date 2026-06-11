#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(int)(a); i++)
typedef long long ll;

int main()
{
  string s; cin>>s;
  string t = "CODEFESTIVAL2016";
  int n = s.size();
  int cnt = 0;
  rep(i, n) if (s[i]!=t[i]) cnt++;
  cout << cnt << endl;

  return 0;
}
