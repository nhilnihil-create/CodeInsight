#include <iostream>
#define ll long long
using namespace std;

ll arr[100005];
ll prefp[100005];
ll prefsum[100005];
int main() {
  int n, k;
  cin >> n >> k;

  prefp[0] = 0;
  prefsum[0] = 0;
  for (int i = 1; i <= n; i++){
    cin >> arr[i];
    if (i == 1){
      prefsum[i] = arr[i];
      if (arr[i] > 0)
        prefp[i] = arr[i];
      else
        prefp[1] = 0;
    }
    else{
      prefsum[i] = prefsum[i-1] + arr[i];
      if (arr[i] > 0)
        prefp[i] = prefp[i-1] + arr[i];
      else
        prefp[i] = prefp[i-1];
    }
  }

  ll ans = 0;
  for (int i = k; i <= n; i++){
    ll temp = 0;
    temp = prefp[i-k] + (prefp[n] - prefp[i]) + max((prefsum[i] - prefsum[i-k]),0ll);
    if (temp > ans)
      ans = temp;
  }

  cout << ans << endl;
  return 0;
}