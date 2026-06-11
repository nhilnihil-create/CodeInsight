#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const ll INF = 1LL<<60;

int main()
{
  ll N;cin>>N;
  ll wari = pow(10, 9)+7;
  ll power = 1;

  for(ll i = 1; i < N+1; i ++) {
    power *= i;
    power %= wari;
  }

  cout << power << endl;
  return 0;
}