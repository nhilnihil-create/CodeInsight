#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;

  int alimit = f / (100 * a);
  int blimit = f / (100 * b);
  int climit = f / c;
  int dlimit = f / d;

  double max = 0;
  int answ = a*100;
  int anss = 0;
  rep (i, alimit + 1){
    rep (j, blimit + 1){
      rep (k, climit + 1){
        rep (l, dlimit + 1){
          int w = 100*a*i + 100*b*j;
          int s = c*k + d*l;
          if (w+s <= f){
            if ((w != 0) || (s != 0)){
              if (e*w >= (s*100)){
                double dens = (1.0*s) / (w+s);
                if (max < dens){
                  max = dens;
                  answ = w;
                  anss= s;
                }
              }
            }
          }
        }
      }
    }
  }
  cout << answ + anss << " " << anss << endl;
  return 0;
}