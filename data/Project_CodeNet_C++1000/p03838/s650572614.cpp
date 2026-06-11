#include <bits/stdc++.h>
#include <math.h>
#include <cmath>
using namespace std;
using ll = long long;
using ull = unsigned long long;


int main (){
  ll x,y; cin >> x >> y;
  
  ll s = abs(x) - abs(y);
  ll t = abs(y) - abs(x);

  if(x >= 0 && y > 0){
    if(x > y){cout << s + 2 << endl;}
    else{cout << t << endl;}
  }
  else if(x >= 0 && y <= 0){
    if(abs(x) >= abs(y)){cout << s + 1 << endl;}
    else{cout << t + 1 << endl;}
  }
  else if(x < 0 && y > 0){
    if(abs(x) >= abs(y)){cout << s + 1 << endl;}
    else{cout << t + 1 << endl;}
  }
  else if(x < 0 && y <=0){
    if(abs(x) >= abs(y)){cout << s << endl;}
    else{cout << t + 2 << endl;}
  }
}