#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  map<int, int> m;
  for (int i=0; i<n; i++) {
    int a;
    cin>>a;
    ++m[a];
  }
  if (m.size() > 2) {
    cout<<"No"<<endl;
    return 0;
  }
  vector<pair<int, int> > v(m.begin(), m.end());
  if (v.size() == 1) {
    if (v[0].first == n - 1 || v[0].first * 2 <= n) {
      cout<<"Yes"<<endl;
      return 0;
    } else {
      cout<<"No"<<endl;
      return 0;
    }
  }
  pair<int, int> b = v[0];
  pair<int, int> c = v[1];
  if (c.first != b.first + 1) {
      cout<<"No"<<endl;
  } else if (c.first - b.second <= 0) {
      cout<<"No"<<endl;
  } else if (2 * (c.first - b.second) <= c.second) {
      cout<<"Yes"<<endl;
  } else {
      cout<<"No"<<endl;
  }
}