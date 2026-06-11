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
ll gcd(ll a,ll b){
  if(a % b == 0)return b;
  else{
     return(gcd(b,a% b));
  }
}
int main(){
  ll n,k;
  cin >> n >> k;
  vector<ll> m(n);
  for(int i = 0;i < n;i++){
    cin >> m[i];
  }
  sort(m.begin(),m.end());
  if(n == 1){
    if(m[0] == k)cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  if(m[0] == k){
    cout << "POSSIBLE" << endl;
    return 0;
  }
  ll now = 0;
  //now = m[1] - m[0];
  now = m[0];
  for(int i = 1;i < n - 1;i++){
    //int memo = m[i + 1]  - m[i];
    //if(memo == 0)continue;
    //now = gcd(now,memo);
    now = gcd(now,m[i]);
    if(m[i] == k){
    cout << "POSSIBLE" << endl;
    return 0;
    }
  }
  if(k > m[m.size() - 1] || k % now != 0){
    cout << "IMPOSSIBLE" << endl;
  }
  else{
    cout << "POSSIBLE" << endl;
  }
  //cout << now << endl;
}