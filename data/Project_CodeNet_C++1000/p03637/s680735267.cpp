#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define MOD 1000000007

int main(void) {
  int n;
  cin >> n;
  ll a[n];
  rep(i,n) cin >> a[i];

  //2の倍数は2人で2個分
  //4の倍数は1人で3人分
  int cnt_4 = 0, cnt_2 = 0;
  rep(i,n){
    if(a[i] % 4==0) cnt_4++;
    if(a[i] % 2==0 && a[i] % 4 != 0) cnt_2++;
  }
  n -= cnt_4*2;
  n -= cnt_2/2*2;
  n -= 1;
  if(n > 0) cout << "No" << endl;
  else cout << "Yes" << endl;
}