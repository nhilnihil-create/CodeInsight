#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  string s, t;
  cin >> s >> t;
  if(s.size() < t.size()) cout << "LESS" << endl;
  else if(s.size() > t.size()) cout << "GREATER" << endl;
  else{
    if(s < t) cout << "LESS" << endl;
    else if(s > t) cout << "GREATER" << endl;
    else cout << "EQUAL" << endl;
  }

  return 0;
}