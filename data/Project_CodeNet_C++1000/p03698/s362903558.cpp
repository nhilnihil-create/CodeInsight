#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  
  unsigned moto = s.size();
  set<char> S;
  
  for(unsigned i = 0;i < moto;i ++){
    S.insert(s[i]);
  }
  
  if(S.size() == moto)cout << "yes" << endl;
  else cout << "no" << endl;
}