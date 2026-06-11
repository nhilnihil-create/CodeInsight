#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

int main() {
  cout << fixed << setprecision(10);
  int n;
  cin >> n;
  ll ans=1;
  for(int i=1; i<=n; i++){
    ans*=i;
    ans%=MOD;
  }
  cout << ans << endl;
}
