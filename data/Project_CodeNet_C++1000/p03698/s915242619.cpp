#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  map<char,int>cou;
  for(int i=0;i<s.size();i++)
    cou[s.at(i)]++;
  bool ok=true;
  for(pair<char,int> i:cou)
    if(i.second>1)
      ok=false;
  cout << (ok?"yes":"no") << endl;
}