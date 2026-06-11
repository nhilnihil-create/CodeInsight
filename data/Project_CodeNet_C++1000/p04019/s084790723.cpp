#include<iostream>
#include<string>
#include<set>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  string s;
  cin >> s;

  set<char> v, h;
  for (char c:s) {
    if (c == 'N' || c == 'S') v.insert(c);
    if (c == 'E' || c == 'W') h.insert(c);
  }

  if (v.size() % 2 == 0 && h.size() % 2 == 0) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
