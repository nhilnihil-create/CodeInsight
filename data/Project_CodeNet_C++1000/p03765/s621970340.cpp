#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  int n = s.size();
  int m = t.size();
  vector<int> ls(n+1), lt(m+1);
  for (int i = 0; i < n; ++i) {
    ls[i+1] = ls[i];
    if (s[i] == 'A') ls[i+1] += 1;
    else ls[i+1] += 2;
    ls[i+1] %= 3;
  }
  for (int i = 0; i < m; ++i) {
    lt[i+1] = lt[i];
    if (t[i] == 'A') lt[i+1] += 1;
    else lt[i+1] += 2;
    lt[i+1] %= 3;
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) { 
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int is = (ls[b]-ls[a-1]+3)%3;
    int it = (lt[d]-lt[c-1]+3)%3;
    if (is == it) cout << "YES" << endl;
    else cout << "NO" << endl;
  }

}
