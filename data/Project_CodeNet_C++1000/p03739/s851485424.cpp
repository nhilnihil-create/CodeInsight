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
  ll n = 0;
  cin >> n;
  vector<ll> num(n);
  for(int i = 0;i < n;i++)cin >> num[i];
  ll now = 0;
  ll wa = 0;
  now = 1;
  ll count = 0;
  ll res = 0;
  res = INT_MAX;
  for(int i = 0;i < n;i++){
    wa += num[i];
    if(now == 1 && wa < now)count += now - wa,wa = 1;
    else if(now == -1 && wa > now)count += wa - now,wa = -1;
    now *= -1;
      //cout << i << " "<< wa << " " << count<< endl;
  }
  res = count;
  wa = 0;
  now = -1;
  count = 0;
  for(int i = 0;i < n;i++){
    wa += num[i];
    if(now == 1 && wa < now)count += now - wa,wa = 1;
    else if(now == -1 && wa > now)count += wa - now,wa = -1;
    now *= -1;
  }
  res = min(count,res);
  cout << res << endl;
}