#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  s+=s.at(11);
  for(int i=10;i>=4;--i){
    s.at(i+1)=s.at(i);
  }
  s.at(4)=' ';
  cout << s << endl;
}