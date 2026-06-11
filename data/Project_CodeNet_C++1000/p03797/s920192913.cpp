#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define All(V) v.begin(), v.end()
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD = 1e9+7, INF = 1e9;

int main()
{
  ll a, b; cin >> a >> b;
  if(a*2 >= b){
    cout << b/2 << endl;
  }
  else{
    ll ans = 0;
    ans += a;
    b -= a*2;
    ans += b/4;
    cout << ans << endl;
  }
  system("pause");
}