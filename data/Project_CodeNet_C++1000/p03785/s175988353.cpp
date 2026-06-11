#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;

ll arr [100005];
int main() {
  int n; ll c, k;
  cin >> n >> c >> k;

  for (int i=1; i <= n; i++){
    cin >> arr[i];
  }
  
  sort (arr+1,arr+n+1);

  ll ans = 1;
  ll track = 0;
  ll org = 0;
  for (int i=1; i <= n; i++){
    ll a = arr[i];
    ll b = arr[i-1];
    
    if (track == 0){
      track++;
      org = a;
    }
    else{
      if (track+1 <= c && a-org <= k){
        track++;
      }
      else{
        ans++;
        track = 1;
        org = a;
      }

    }

  }   

  cout << ans << endl;
  return 0;
}