#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
int main(){
  ll n,m;
  cin >> n >> m;
  if(n == 1){
    cout << 1 << endl;
    return 0;
  }
  if(m == 1){
    cout << n << endl;
    return 0;
  }
  vector<vector<ll>> like(n,vector<ll>(m));
  for(int i = 0;i < n;i++){
    for(int j = 0;j < m;j++){
      cin >> like[i][j];
      like[i][j]--;
    }
  }
  ll res = 0;
  res = 100000;
  vector<bool> play(m);
  for(int i = 0;i < m;i++)play[i] = true;
  for(int i = 0;i < m - 1;i++){
    vector<ll> now(m);
    for(int j = 0;j < m;j++)now[j] = 0;
    for(int j = 0;j < n;j++){
      for(int k = 0;k < m;k++){
        if(play[like[j][k]]){
          now[like[j][k]]++;
          k = m;
        }
      }
    }
    ll big = 0;
    ll bn = 0;
    for(int j = 0;j < m;j++){
      if(big < now[j]){
        big = now[j];
        bn = j;
      }
    }
    res = min(res,big);
    play[bn] = false;
  }
  cout << res << endl;
}