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
  if(x > 0){
    if(y <= -x){
      a = - y - x + 1;
    }
    else if(y >= x){
      a = y - x;
    }
    else if(y > 0 && y < x){
      a = 2 - y + x;
    }
    else{
      a = 1 + y + x;
    }
  }
  else if(x < 0){
    if(y < x){
      a = 2 - y + x;
    }
    else if(y >= -x){
      a = 1 + y + x;
    }
    else if(y > 0 && y < -x){
      a = 1 - y - x;
    }
    else{
      a =y - x;
    }
  }
  else{
    if(y >= 0){
      a = y - x;
    }
    else{
      a = -y - x + 1;
    }
  }
  cout << a << endl;
  return 0;
}