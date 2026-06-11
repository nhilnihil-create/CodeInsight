// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
#define chmax(x,y) (x = max(x, y))
void solve(); int main() { solve(); return 0; }

void solve() {
  set<int> S;
  loop(i,0,3) {
    int a;
    cin >> a;
    S.insert(a);
  }
  cout << S.size() << endl;
}
