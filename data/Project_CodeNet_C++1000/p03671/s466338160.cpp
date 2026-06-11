// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
#define chmax(x,y) (x = max(x, y))
void solve(); int main() { solve(); return 0; }

void solve() {
  vector<int> S;
  loop(i,0,3) {
    int a;
    cin >> a;
    S.push_back(a);
  }
  sort(S.begin(), S.end());
  cout << S[0]+S[1] << endl;
}
