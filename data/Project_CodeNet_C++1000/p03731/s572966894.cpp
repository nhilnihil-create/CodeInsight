#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int max_n = 1e6;
int t[5][5];
ll n,T;
int ans = 1;
bool memo[15][15] = {0};
int main(){
  cin >> n >> T;
  ll t[n];
  for(int i=0 ; i<n ; i++){
    cin >> t[i];
  }
  ll now = 0;
  ll sum = 0;
  for(int i=0 ; i<n ; i++){
    if(now <= t[i]){
      sum += T;
      now = t[i]+T;
    }else{
      sum += t[i] + T - now;
      now = t[i]+T;
    }
  }
  cout << sum << endl;
  return 0;
}
