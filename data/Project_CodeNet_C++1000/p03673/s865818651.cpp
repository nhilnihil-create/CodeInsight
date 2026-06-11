#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG



signed main() {
  int n; cin >> n;
  
  deque<int> d;
  
  rep(i, n) {
    int a; cin >> a;
    if(i%2 == 0) {
      d.push_back(a);
    } else {
      d.push_front(a);
    }
  }
  
  if(n%2 == 0) {
    rep(i, n) {
      cout << d.front() << " ";
      d.pop_front();
    }
  } else {
    rep(i, n) {
      cout << d.back() << " ";
      d.pop_back();
    }
  }
  
  cout << endl;
  
}
