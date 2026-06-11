#include <bits/stdc++.h>

using namespace std;

int main(){
  int a, b, c, d, e, f;
  double mx=0.0;
  cin >> a >> b >> c >> d >> e >> f;
  int mx_total=100*a, mx_sugar=0;
  for(int aa=0;aa*a*100<=f;aa++){
    for(int bb=0;(aa*a+bb*b)*100<=f;bb++){
      int water=(aa*a + bb*b)*100;
      for(int cc=0;water+cc*c<=f;cc++){
        if(e*water/100<c*cc)break;
        for(int dd=0;water+cc*c+dd*d<=f;dd++){
          int sugar=cc*c + dd*d;
          if(e*water/100<c*cc+d*dd)break;
          double d_sugar = (double)sugar;
          double d_water = (double)water;
          double value = (d_sugar)/(d_sugar+d_water);
          if(value>mx){
            mx=value;
            mx_total=sugar+water;
            mx_sugar=sugar;
          }
        }
      }
    }
  }
  cout << mx_total << ' ' << mx_sugar << endl;
}

