#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


int main(){
  fastIO;
  ll n;
  ll a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  --n;
  ll x = max(b-a,a-b);
  ll j;
  ll li, ri;
  ll lj, rj;
  for(ll i = 0 ; i <= n ; i ++ ){
    j = n - i;
    li = i * c;
    ri = i * d;
    lj = j * c;
    rj = j * d;
    if(x >= li - rj && x <= ri - lj){
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}