#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
#define P pair<int, int>
using namespace std;

const int M = 1000005;

int main() {
  string o, e;
  cin >> o >> e;
  rep(i, e.size()){
    cout << o[i] << e[i];
  }
  if(o.size() > e.size()) cout << o[o.size()-1];
  return 0;
}
