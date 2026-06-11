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
  vector<ll> under(n);
  for(int i = 0;i < n;i++)under[i] = pow(10,18);
  vector<ll> de(n);
  for(int i = 0;i < n;i++)de[i] = -1;
  
  vector<ll> t(n);
  vector<ll> a(n);
  for(int i = 0;i < n;i++)cin >> t[i];
  for(int i = 0;i < n;i++)cin >> a[i];
  
  for(int i = 0;i < n;i++){
    if(i == 0){
      de[i] = t[i];
    }
    else if(t[i] > t[i - 1]){
      de[i] = t[i];
    }
    else{
      under[i] = t[i];
    }
  }
  for(int i = n - 1;i >= 0;i--){
    if(i == n - 1){
      if((de[i] != a[i] && de[i] != -1) || (a[i] > under[i])){
        cout << 0 << endl;
        return 0;
      }
      de[i] = a[i];
    }
    else if(a[i] > a[i + 1]){
      if((de[i] != a[i] && de[i] != -1) || (a[i] > under[i])){
        cout << 0 << endl;
        return 0;
      }
      de[i] = a[i];
    }
    else{
      if(de[i] > a[i]){
        cout << 0 << endl;
        return 0;
      }
      under[i] = min(under[i],a[i]);
    }
  }
  ll res = 1;
  ll mod = pow(10,9) + 7;
  for(int i = 0;i < n;i++){
    if(de[i] == -1){
      res *= under[i],res %= mod;
    }
  }
  cout << res << endl;
}