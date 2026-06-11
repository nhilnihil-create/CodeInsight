#include <iostream>
#include <algorithm>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using namespace std;

int main() {
  int n; cin >> n;
  vector<pair<int, int> > p(n);

  rep(i, n) {
    int a; cin >> a;
    p[i] = make_pair(a, i);
  }
  
  sort(p.begin(), p.end());

  int ans = 0;
  rep(i, n) {
    if ( p[i].second%2 != i%2 ) { ans++; }
  }

  cout << (ans+1)/2 << endl;

  return 0;
}