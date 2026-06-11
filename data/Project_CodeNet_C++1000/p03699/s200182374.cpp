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
  ll sum = 0;
  vector<ll> s(N);
  for (int i = 0; i < N; i++){
    ll tmp = 0;
    cin >> tmp;
    sum += tmp;
    s[i] = tmp;
  }
  if(sum%10!=0){
    cout << sum << endl;
    return 0;
  }
  sort(s.begin(), s.end());
  for (int i = 0; i < N; i++) {
      if(s[i]%10!=0){
        cout << sum - s[i] << endl;
        return 0;
      }
  }
  cout << 0 << endl;
  return 0;
}