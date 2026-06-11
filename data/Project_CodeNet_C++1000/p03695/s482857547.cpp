#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;
const ll MOD = 1000000007;
using pint = pair<ll, ll>;

int main() {
  ll N;
  cin >> N;
  vector<ll> rate(9, 0);
  for (int i = 0; i<N; i++){
    ll tmp = 0;
    cin >> tmp;
    if (tmp >= 1 && tmp <= 399) rate[0]++;
    if (tmp >=400 && tmp <= 799) rate[1]++;
    if (tmp >= 800 && tmp <= 1199) rate[2]++;
    if (tmp >= 1200 && tmp <= 1599) rate[3]++;
    if (tmp >= 1600 && tmp <= 1999) rate[4]++;
    if (tmp >= 2000 && tmp <= 2399) rate[5]++;
    if (tmp >= 2400 && tmp <= 2799) rate[6]++;
    if (tmp >= 2800 && tmp <= 3199) rate[7]++;
    if (tmp >= 3200) rate[8]++;
  }
  ll cnt = 0;
  for (int i = 0; i < 8; i++){
    if (rate[i] != 0) cnt++;
  }
  if(cnt==0){
      cout << 1 << " " << rate[8] << endl;
      return 0;
  }
  cout << cnt << " " <<cnt+rate[8] << endl;
  return 0;
}