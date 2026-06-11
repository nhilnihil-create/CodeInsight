#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
typedef long long ll;
int main(){
  ll x,y;
  cin >> x >> y;
  ll a = 0;
  a = pow(10,15);
  ll b = 0;
  b = y - x;
  if(b >= 0){
    a = min(a,b);
  }
  b = 1 + y + x;
  if(b >= 0){
    a = min(a,b);
  }
  b = 1 - y - x;
  if(b >= 0){
    a = min(a,b);
  }
  b = 2 - y + x;
  if(b >= 0){
    a = min(a,b);
  }
  cout << a << endl;
  return 0;
}