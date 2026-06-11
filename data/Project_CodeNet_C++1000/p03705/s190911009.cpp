#include <bits/stdc++.h>
using namespace std;
#define rep(i, seisu) for(int i = 0; i < (int)(seisu); i++)
typedef long long ll;


int main(){
  ll n, min, max;
  cin >> n >> min >> max;
  ll diff = max - min;
  ll ans = 0;
  if(diff > 0 &&  n > 1){
    ll maxsum = min + max * (n-1);
    ll minsum = min * (n-1) + max;
    ans = maxsum - minsum + 1;
  }
  else if(diff == 0 && n >= 1){
    ans = 1;
  }
  cout << ans << endl;
}

