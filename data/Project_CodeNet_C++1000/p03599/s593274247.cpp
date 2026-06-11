#include <bits/stdc++.h>
using namespace std;
int main(){
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  double max_n = 0;
  int ans_1 = 100*a, ans_2 = 0;
  for(int i=0; i*a*100<=f; ++i){
    for(int j=0; j*b*100<=f; ++j){
      int w = (a*i+b*j)*100;
      if(w == 0) continue;
      for(int k=0; k*c<=f-w; ++k){
        for(int l=0; l*d<=f-w; ++l){
          int s = k*c+l*d;
          if(s == 0 || w+s > f || s > (w/100)*e) continue;
          double n = 100*s*1.0/((w+s)*1.0);
          max_n = max(max_n, n);
          if(n != max_n) continue;
          ans_1 = w+s;
          ans_2 = s;
        }
      }
    }
  }
  cout << ans_1 << " " << ans_2 << endl;
}