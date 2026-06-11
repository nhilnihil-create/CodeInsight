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
long long mod = 1000000000000000000;
long long power(long long m,long long n){
    long long res = 1;
    if(n > 0){
        res = power(m,n / 2);
        if(n % 2 == 0){
            res = (res * res) % mod;
        }
        else{
            res = (((res * res) % mod) * m) % mod;
        }
    }
    return res;
}
//modはグローバル変数にしておく
int main(){
  ll n = 0;
  ll p = 0;
  cin >> n >> p;
  vector<ll> count(2);
  count[0] = 0;
  count[1] = 0;
  for(int i = 0;i < n;i++){
    ll num = 0;
    cin >> num;
    count[num % 2]++;
  }
  ll res = 0;
  if(count[1] > 0)res = power(2,n-1);
  else {
    if(p == 0)res= power(2,n);
    else res = 0;
  }
  cout << res << endl;
  return 0;
}