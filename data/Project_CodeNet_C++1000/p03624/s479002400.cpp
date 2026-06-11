// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
void solve(); int main() { solve(); return 0; }

void solve() {
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  s.erase(unique(s.begin(), s.end()), s.end());
  int n = s.size();
  if (n==26) {
    cout << "None" << endl;
    return;
  }
  
  loop(i,0,26) {
    char c = (char)(i+'a');
    if (c != s[i]) {
      cout << c << endl;
      return;
    }
  }
}
