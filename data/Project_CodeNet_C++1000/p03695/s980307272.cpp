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
  ll free = 0;
  map<ll,ll> mp;
  for(int i = 0;i < n;i++){
    ll r = 0;
    cin >> r;
    if(r >= 3200)free++;
    else mp[r / 400]++;
  }
  cout << max((ll)mp.size(),(ll)1) << " " << (ll)mp.size() + free << endl;
}