#include <bits/stdc++.h>
       
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
  string s;
  cin >> s;
  cout << ((s.size() % 2) ^ (s[0] == s[s.size() - 1]) ? "First" : "Second")
       << endl;
  return 0;
}
