#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s;
  cin >> s ;
  vector<char> a;
  
  for(int i =0; i < s.size() ; i++){
    if(s.at(i) == '0') a.push_back('0');
    else if(s.at(i) == '1') a.push_back('1');
    else if(s.at(i) == 'B' && a.size() > 0) a.pop_back();
  }
  for(int i=0; i < a.size() ; i++) cout << a.at(i) ;
}