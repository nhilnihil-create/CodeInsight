#include<bits/stdc++.h>
using namespace std;

int main(){
  string s,t;
  string kekka = "";
  
  cin >> s >> t;
  
  for(int i = 0; i < t.size(); i++){
    kekka += s.substr(i,1) + t.substr(i,1);
  }

  if(s.size() > t.size()) kekka += s.substr(s.size()-1,1);
  
  cout << kekka;
}