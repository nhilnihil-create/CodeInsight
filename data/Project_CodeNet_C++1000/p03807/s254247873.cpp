#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const ll INF = 1LL<<60;

int main()
{
  ll N;cin>>N;
  // ll A[N];
  // ll even=0;
  ll odd =0;
  rep(i, N) {
    ll tmp; cin>>tmp;
    if(tmp%2!=0) odd++;
  }

  if(odd%2==0) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}