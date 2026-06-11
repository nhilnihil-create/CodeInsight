#include <iostream>
using namespace std;

typedef long long ll;
const ll MOD = (1e+9) + 7;

int n;
int t[100000], a[100000];

int main()
{

  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> t[i]; 
  }
  for(int i = 0; i < n; i++){
    cin >> a[i]; 
  }

  ll ans = 1;
  if(t[n-1] != a[0]) ans = 0;
  for(int i = 1; i < n-1; i++){
    if(t[i] == t[i-1] && a[i] == a[i+1]){
      ans *= min(t[i], a[i]);
      ans %= MOD;
    }
    else if(t[i] > t[i-1] && a[i] == a[i+1] && t[i] > a[i]) ans = 0;
    else if(t[i] == t[i-1] && a[i] == a[i+1] && t[i] < a[i]) ans = 0;
    else if(t[i] > t[i-1] && a[i] > a[i+1] && a[i] != t[i]) ans = 0;
  }

  cout << ans << endl;

  return 0;
}
