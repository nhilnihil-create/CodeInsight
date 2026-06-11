#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll n;
  cin >> n;
  vector<ll> ar(n);

  for(ll i = 0; i < n; i++){
    cin >> ar[i];
  }

  ll ans1, ans2;
  ans1 = ans2 = 0; 
  ll cum = 0;
 
    //偶数が正の場合
  for(ll i = 0; i < n; i++){
    cum += ar[i];
    if(i % 2 == 0){
        if(cum <= 0){
            ans1 += abs(cum - 1);
            cum = 1;
        }
    }else{
        if(cum >= 0){
            ans1 += abs(cum + 1);
            cum = -1;
        }
    }
  }

   //偶数が負の場合
  cum = 0;

  for(ll i = 0; i < n; i++){
    cum += ar[i];
    if(i % 2 == 0){
        if(cum >= 0){
            ans2 += abs(cum + 1);
            cum = -1;
        }
    }else{
        if(cum <= 0){
            ans2 += abs(cum - 1);
            cum = 1;
        }
    }
  }
  
    ll prans = min(ans1, ans2);

  cout << prans << endl;

  return 0;

}
