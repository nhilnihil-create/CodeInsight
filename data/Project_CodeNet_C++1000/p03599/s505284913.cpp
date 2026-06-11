#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
  int A,B,C,D,E,F;
  cin >> A >> B >> C >> D >> E >> F;
  double x=-1;
  int max_all=0, max_su=0;
  for(int a=0; 100*A*a<=F; a++) {
    for(int b=0; 100*B*b<=F; b++) {
      int s = (A*a+B*b)*E;
      for(int c=0; C*c<=s; c++) {
        for(int d=0; D*d<=s; d++) {
          int su = C*c+D*d;
          int all = 100*A*a + 100*B*b + su;
          if(su > s) continue;
          if(all > F) continue;
          if(x < 100*su / (double)all) {
            x = 100*su / (double)all;
            max_all = all;
            max_su = su;
          }
        }
      }
    }
  }
  cout << max_all << " " << max_su <<endl;
}