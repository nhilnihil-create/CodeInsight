#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;

  string T="CODEFESTIVAL2016";
  int ans=0;
  for(int i=0;i<S.size();i++) if(S.at(i)!=T.at(i))  ans++;
  cout << ans << endl;

  return 0;
}