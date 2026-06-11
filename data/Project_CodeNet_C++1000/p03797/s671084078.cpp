#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define MOD 1000000007

int main(void) {
  ll n, m;
  cin >> n >> m;
  //sが余る場合
  if(n*2 > m) {
    cout << m/2 << endl;
  } else {
     m += n*2;
  n=0;
  cout << m/4 << endl;
}
  }
 