#include <iostream>
using namespace std;

int main(){
  double A, B, C, D, E, F;
  cin >> A >> B >> C >> D >> E >> F;
  A *= 100;
  B *= 100;
  int ans1=A,ans2=0;
  double tmp_dens = 0.0;
  for(int i=1; A*i<=F; i++){
    for(int j=0; A*i+B*j<=F; j++){
      double w = A*i+B*j;
      for(int k=0; w+C*k<=F && C*k<=E*w/100; k++){
        int l_1 = static_cast<int>((F-w-C*k)/D);
        int l_2 = static_cast<int>((E*w/100-C*k)/D);
        int l = max(0,min(l_1, l_2));
        double s = C*k+D*l;
        if(tmp_dens<s/(s+w)){
          ans1 = s+w;
          ans2 = s;
          tmp_dens = s/(s+w);
        }
      }
    }
  }
  cout << ans1 << " " << ans2;
  return 0;
}
