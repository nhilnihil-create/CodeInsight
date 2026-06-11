#include <bits/stdc++.h>
using namespace std;

long long N, K;
vector<long long> sumV(100001);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;

  int a, b, c;
  cin >> a >> b >> c;
  set<int> s;
  s.insert(a);
  s.insert(b);
  s.insert(c);
  
  cout << s.size() <<endl;
}
