#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  int p=0;
  for(int i=1; i<S.size(); i++){
    if(S.at(i)=='p') p++;
  }
  int ans= S.size()/2-p;
  
  cout << ans << endl;
}
