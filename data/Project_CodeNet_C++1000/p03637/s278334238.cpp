#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a.at(i);
  int cnt2 = 0;
  rep(i,n)if(a.at(i)%2 == 0) cnt2++;
  int cnt4 = 0;
  rep(i,n)if(a.at(i)%4 == 0) cnt4++;
  cnt2 -= cnt4;
  bool ans  = false;
  if(cnt4 >= n/2) ans = true;
  else if(cnt2 >= n-2*cnt4) ans = true;
  cout <<(ans?"Yes":"No") << endl;
}