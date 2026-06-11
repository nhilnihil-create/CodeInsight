#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  string s; cin >> s;

  string res = s.front() + to_string(s.size() - 2) + s.back();
  cout << res << "\n";
}
