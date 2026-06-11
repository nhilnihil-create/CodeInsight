#include<bits/stdc++.h>
#define REP(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
const ll MOD = 1000000007;

int main() {
  int n, l, s = 0;
  vector<int> v;
  cin >> n;
  REP(i, n * 2) {
    cin >> l;
    v.push_back(l);
  }
  sort(v.rbegin(), v.rend());

  REP(i, n) {
    s += min(v[i * 2], v[i * 2 + 1]);
  }

  cout << s << endl;
  return 0;
}