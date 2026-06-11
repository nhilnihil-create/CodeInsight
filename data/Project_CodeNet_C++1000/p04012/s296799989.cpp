// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
#define chmax(x,y) (x = max(x, y))
//  cout.precision(15); cout << fixed;


int main() {
  string s; cin >> s;
  map<char, int> M;
  for (auto c: s) {
    M[c]++;
  }
  
  for (auto c: s) {
    if (M[c]%2==0) continue;
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  return 0;
}
