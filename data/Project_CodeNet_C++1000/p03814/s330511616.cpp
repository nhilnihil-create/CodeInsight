#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  int l = s.size(), pA, pZ;
  bool fA = false, fZ = false;
  for(int i=0,j=l-1; i<l; ++i,--j){
    if(!fA && s[i] == 'A'){
      pA = i;
      fA = true;
    }
    if(!fZ && s[j] == 'Z'){
      pZ = j;
      fZ = true;
    }
    if(fA && fZ){
      cout << pZ-pA+1 << endl;
      return 0;
    }
  }
}