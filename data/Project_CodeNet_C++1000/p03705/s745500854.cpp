#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t N,Vmin,Vmax;
  cin >> N >> Vmin >> Vmax;

  int64_t ans= (N==1) ? ((Vmax==Vmin) ? 1
                                      : 0)
              :(Vmax < Vmin)          ? 0
                                      : (N-2)*(Vmax-Vmin)+ 1;

  cout << ans << endl;
}