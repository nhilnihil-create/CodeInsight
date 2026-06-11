// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
//  cout.precision(15); cout << fixed;

int main() {
  string s; cin >> s;
  int n=s.size();
  loop(i,0,n) {
    if (i%2==1) continue;
    cout << s[i];
  }
  cout << endl;
  return 0;
}
