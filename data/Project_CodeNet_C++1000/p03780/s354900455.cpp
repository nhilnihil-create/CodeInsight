#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

//-------------------------↓↓↓↓↓↓------------------------

ll a[5001], le, ri, mid, n, k, ans;

bool okk(ll i){

  bool tmp, ok = true;

  if(k <= a[i]){
    return true;
  }

  bitset<5000 + 10> dp;
  dp[0] = true;

  for(int j = 0; j < n; j++){
    if(i == j)continue;
    dp |= (dp << a[j]);
  }

  for(int j = k - a[i]; j < k; j++){
    if(dp[j]){
      ok = false;
      break;
    }
  }

  if(!ok)tmp = true;
  else tmp = false;

  return tmp;

}

int main(void){

       cin.tie(0);
    ios::sync_with_stdio(false);

      cin >> n >> k;

      for(int i = 0; i < n; i++){
        cin >> a[i];
      }

      sort(a, a + n);

      le = 0, ri = n - 1, mid;

      while(ri - le > 1){

        mid = (le + ri) / 2;

        if(okk(mid)){
          ri = mid;
        }
        else{
          le = mid;
        }
        
      }

      if(!okk(ri))ans = ri + 1;
      else if(!okk(le))ans = le + 1;
      else ans = le;

      cout << ans << "\n";
    
       
return 0;
}
