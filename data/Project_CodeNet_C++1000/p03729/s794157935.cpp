#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  string s, t, u;
  cin >> s >> t >> u;
  if(s[s.size() - 1] == t[0] && t[t.size() - 1] == u[0]) cout << "YES" << "\n";
  else cout << "NO" << "\n";
}
