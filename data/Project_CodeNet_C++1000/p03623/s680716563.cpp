#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int x,a,b; cin >>x>>a>>b;
  int amade =max(a-x,x-a),bmade=max(b-x,x-b);
  if(min(amade,bmade) == amade) cout << 'A' << endl;
  else cout << 'B' << endl;
}
