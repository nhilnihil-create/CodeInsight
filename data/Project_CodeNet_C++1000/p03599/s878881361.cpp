#include <bits/stdc++.h>
#include <vector>
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;
using namespace std;
int main(){
  int a,b,c,d,e,f;
  cin >> a >> b >> c >> d >> e >> f;
  vector<int> sMass;
  vector<int> wMass;
  rep(i, f + 1){
    rep(j, f + 1){
      //if(!i && !j) continue;
      int s = c * i + d * j;
      if(s <= f){ // s <= f
        sMass.push_back(s);
      }
      if(!i && !j) continue;
      int w = 100 * a * i + 100 * b * j;
      if(w <= f){
        wMass.push_back(w);
      }
    }
  }
  int sans = 0;
  int wans = 0;
  bool first = true;
  rep(i, sMass.size()){
    rep(j, wMass.size()){
      if(sMass[i] + wMass[j] <= f){
        if(first){
          if(sMass[i] * (100 + e) > e * (sMass[i] + wMass[j])) continue; //反対の項に分母をかける
          sans = sMass[i];
          wans = wMass[j];
          first = false;
          continue;
        }
        if(sMass[i] * (100 + e) > e * (sMass[i] + wMass[j])) continue;
        if(sans * (sMass[i] + wMass[j]) < sMass[i] * (sans + wans)){
          sans = sMass[i];
          wans = wMass[j];
        }
      }
    }
  }
  cout << wans + sans << " " << sans << endl;
  return 0;
}