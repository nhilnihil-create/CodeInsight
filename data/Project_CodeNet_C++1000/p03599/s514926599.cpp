#include <bits/stdc++.h>
using namespace std;

int main() {
  double A,B,C,D,E,F;
  cin >> A >> B >> C >> D >> E >> F;
  
  double max = 0.0; 
  double S = 0.0;
  double T = 0.0;
  
  for (int i = 0; i <= F/(100.0*A); i++) {
    for (int j = 0; j <= F/(100.0*B); j++) {
      for (int k = 0; k <= F/C; k++) {
        for (int l = 0; l <= F/D; l++) {
          if ( (C*k+D*l)/(100.0*A*i+100.0*B*j+C*k+D*l) <= E/(100.0+E) && (C*k+D*l)/(100.0*A*i+100.0*B*j+C*k+D*l) >= max && 100.0*A*i+100.0*B*j+C*k+D*l <= F) {
            max = (C*k+D*l)/(100.0*A*i+100.0*B*j+C*k+D*l);
            S = 100.0*A*i+100.0*B*j+C*k+D*l;
            T = C*k+D*l;            
          }
        }      
      }
    }
  }

  cout << S << " " << T << endl;
      
}