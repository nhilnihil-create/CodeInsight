#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(int)(a); i++)
typedef long long ll;

int main()
{
  ll n,a,b; cin >> n >> a >> b;

  ll l = a*(n-1)+b;
  ll r = a+(n-1)*b;
  cout << max(0LL, r-l+1) << endl;

  return 0;
}
