// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
//  cout.precision(15); cout << fixed;

typedef pair<ll, ll> P;

int main() {
  string s; cin >> s;
  set<char> S;
  for (auto c: s) {
    if (S.count(c)) {
      cout << "no" << endl;
      return 0;
    }
    
    S.insert(c);
  }
  cout << "yes" << endl;
  return 0;
}
