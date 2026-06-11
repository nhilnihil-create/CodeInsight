// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
//  cout.precision(15); cout << fixed;

int main() {
  int n; cin >> n;
  int t = 0;
  loop(i,0,n) {
    int a, b; cin >> a >> b;
    t += b-a+1;
  }
  cout << t << endl;
  return 0;
}
