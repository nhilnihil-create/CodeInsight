#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
constexpr int INF = 2e9;
typedef tuple<int,int,int> TP;
int main() {
  int a, b;
  char c;
  cin >> a >> c >> b;
  cout << (c == '+' ? a + b : a - b) << endl;
  return 0;
} 