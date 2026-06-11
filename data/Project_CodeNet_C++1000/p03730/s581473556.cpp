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
  ll a,b,c;
  cin >> a >> b >> c;
  c %= a;
  map<ll,ll> mp;
  mp[c]++;
  while(1){
    c += b;
    c %= a;
    mp[c]++;
    if(c == 0){
      cout << "YES" << endl;
      return 0;
    }
    if(mp[c] > 1){
      cout << "NO" << endl;
      return 0;
    }
  }
}