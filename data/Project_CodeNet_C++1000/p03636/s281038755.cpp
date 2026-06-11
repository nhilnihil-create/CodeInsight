#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  char kari[2];
  int count;
  
  cin >> s;
  count = s.size();
  kari[0] = s[s.size() - 1];
  
  s[2] = kari[0];
  
  cout << s[0] << s.size()-2 << s[2] << endl;
  
  return 0;
}