#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  set<int> s;
  rep(i,3){
    int x; cin >> x;
    s.insert(x);
  }
  cout << s.size();
}