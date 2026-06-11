#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<numeric>
using namespace std;
using ll = long long;
int main(){
  ll x, y;
  cin >> x >> y;
  ll cnt = 0;
  if(x == -y){
    cout << 1 << endl;
  }else if(x == 0){
    if(y >= 0){
      cout << y << endl;
    }else{
      cout << -y + 1 << endl;
    }
  }else if(x <= y){
    if(x < 0 && y > 0){
      cout << abs(x + y) + 1 << endl;
    }else{
      cout << y - x << endl;
    }
  }else{
    if(y > 0 && x > 0){
      cout << 2 + abs(y - x) << endl;
    } else if(y <= 0 && x > 0){
      if(x < -y){
        cout << 1 - y - x << endl;
      }else{
        cout << 1 + (y + x) << endl;
      }
    }else{
      cout << 2 - (y - x) << endl;  
    }
  }
  return 0;
}