#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int hantei(int d, int s){
  int r = s % d;
  if(r == 0 || s / d == 0){
    return 1;
  }else{
    return 0;
  }
}

int main(){
  int A, B, C, D, E, F;
  double max = -1;
  int max_s;
  int max_sw;
  cin >> A >> B >> C >> D >> E >> F;
  //for(int f = 100*A; f <= F; f++){
    for(int a = 0; a <= F / 100 ; a++){
      for(int b = 0; b <= F / 100; b++){
        if(a == 0 && b == 0) continue;
        int w = 100 *( A * a + B * b);
        for(int c = 0; c * C <= F-w; c++){
          for(int d = 0; d * D <= F - w - c*C; d++){
            int s = c*C + d*D;
            double per = (100 * s) / (double)(s + w);
            if(max < per && s <= E * (A * a + b * B) ){
              max = per;
              max_s = s;
              max_sw = s + w;
            }
          }
        }
      }
    }
  //}
  cout << max_sw << " " << max_s << endl;
  return 0;
}
