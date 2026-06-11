#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0;i < (int)(n);i++)
int main() {
  int n, a;
  cin >> n;
  set<int> v;
  rep(i, n) {
    cin >> a;
    if(v.count(a)) v.erase(a);
    else v.insert(a);
  }
  cout << v.size() << endl;
}