#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const ll INF=1000000007;

ll fnc(int x) {
  ll y=1;
  for(int i=x; i>0; i--) {
    y*=i;
    y%=INF;
  }
  return y;
}

int main() {
  int n, m;
  cin >> n >> m;
  if(n<m) swap(n,m);
  if(n-m>1) {
    cout << 0 << endl;
    return 0;
  }
  if(n==m) cout << 2*fnc(n)*fnc(m)%INF << endl;
  else cout << fnc(n)*fnc(m)%INF << endl;
}
