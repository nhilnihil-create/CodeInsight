#include <bits/stdc++.h>
using namespace std;


int main(){
  string S;
  cin >> S;
  string C = "CODEFESTIVAL2016";
  int ans = 0;
  for(int ii=0; ii<16; ii++){
    if(S[ii] != C[ii]) ans++;
  }
  cout << ans << endl;
  return 0;
}
