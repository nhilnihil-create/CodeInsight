#include <bits/stdc++.h>
using namespace std;

template<class T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}

int main(){
  double a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  set<double> st;
  for(int i = 0; i * a * 100 <= f; i++){
    for(int j = 0; j * b * 100 <= f; j++){
      if(a*100*i + b*100*j <= f) st.insert(a*100*i + b*100*j);
    }
  }
  int ans1, ans2;
  double tmp = -1;
  for(int water : st){
    double psbl = min(water/100*e, f-water);
    double sugar = -1;
    for(int j = 0; j*c <= psbl; j++){
      for(int k = 0; k*d <= psbl; k++){
        if(c*j + d*k <= psbl) sugar = max(sugar, c*j + d*k);
      }
    }
    if(chmax(tmp, sugar*100/(water + sugar))){
      ans1 = sugar + water;
      ans2 = sugar;
    }
  }
  cout << ans1 << " " << ans2 << endl;    
}