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
  ll n,a,b,c,d;
  cin >> n >> a >> b >> c >> d;
  for(int i = 0;i < n;i++){
    ll l = -1 * d * i + c * (n - i - 1);
    ll r = -1 * c * i + d * (n - i - 1);
    if(l <= b - a && b - a <= r){
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}