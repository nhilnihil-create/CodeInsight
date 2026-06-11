#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))
const int INF = 2000000000;

int n;
int l[1000];

int main(){
  cin >> n;
  rep(i, 2*n) cin >> l[i];
  sort(l, l+2*n);
  ll ans = 0;
  rep(i, n) ans += l[2*i];
  cout << ans <<endl;
}
  