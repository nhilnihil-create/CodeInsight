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
  int n;
  cin >> n;
  ll a[n];
  ll s = n * 1ll *(n + 1) / 2ll;
  ll total = 0;
  for(int i = 0 ; i < n ; i ++ ){
    cin >> a[i];
    total += a[i];
  }
  if(total % s != 0){
    cout << "NO\n";
    return 0;
  }
  if(n == 1){
    cout << "YES\n";
    return 0;
  }
  total /= s;
  ll cur = 0;
  ll x;
  for(int i = 0; i < n ; i ++ ){
    x = a[(i - 1 + n) % n] - a[i];
    x += total;
    if(x < 0){
      cout << "NO\n";
      return 0;
    }
    if(x % n != 0){
      cout << "NO\n";
      return 0;
    }
    cur += x/n;
  }
  if(cur == total)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
