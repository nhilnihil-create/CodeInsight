#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

int main(){
  ll K;
  cin >> K;
  vector<ll> ans(50, 0);
  for(int i=0;i<50;i++)
    ans[i] = 49 - i;
  for(ll i = 0; i<50;i++){
    ans[i] += K/50;
    ans[i] += (K%50) > i;
  }
  cout << 50 << endl;
  for(int i=0;i<50;i++){
    cout << ans[i];
    if(i == 49)
      cout << endl;
    else
      cout << " ";
  }
  return 0;
}
/*
 49 48 47 ... 0 = 0
 50 48 47  .. 0 = 1
 50 49 48 0 .... 0 = 3
 50 49 48 47 ... 1 = 50
 51 49 48 47 ... 1 = 51
 51 50 48 47 ... 1 = 52
 51 50 49 47 ... 1
 */
