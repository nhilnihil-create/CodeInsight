#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int N, E, W, S;
  N=E=S=W=0;
  
  for(int i=0; i<s.size(); i++){
    if(s.at(i)=='N')N=1;
    if(s.at(i)=='W')W=1;
    if(s.at(i)=='E')E=1;
    if(s.at(i)=='S')S=1;
  }
  
  if(S==N && W==E)cout << "Yes" << endl;
  else cout << "No" << endl;
}