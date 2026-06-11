#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define MOD 1000000007

int main(void) {
  ll x;
  cin >> x;
  ll cnt=0;
  cnt += x/11*2;
  x -= x/11*11;
  if(x > 6) cnt+=2;
  else if(x > 0) cnt++;
  cout << cnt << endl;
}