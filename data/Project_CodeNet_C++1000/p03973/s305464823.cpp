#include <iostream>

using namespace std;

typedef long long ll;

ll a[100005];

int main() {
  int n;
  cin >> n;
  
  for(int i = 0; i < n; i++) cin >> a[i];
  
  ll low = 2;
  ll ans = (a[0] - 1);
  for(int i = 1; i < n; i++) {
    if(a[i] < low) continue;
    if(a[i] == low) {
      low++;
      continue;
    }
    ll tmp = (a[i] - 1) / low;
    ans += tmp;
  }
 
  cout << ans << endl;
}
  
