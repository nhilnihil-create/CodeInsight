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
  ll n;
  cin >> n;
  vector<ll> a(n);
  for(int i = 0;i < n;i++)cin >> a[i],a[i]--;
  ll now = 0;
  ll res = -1;
  ll k = 0;
  map<ll,ll> mp;
  while(1){
    mp[now]++;
    k++;
    now = a[now];
    if(mp[now] >= 1)break;
    if(now == 1){
      res = k;
      break;
    }
  }
  cout << res << endl;
}