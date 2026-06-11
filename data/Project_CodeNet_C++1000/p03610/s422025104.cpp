#include <bits/stdc++.h>
using namespace std;

int main() {
 string s;
  cin >> s;
  for( int i= 0; i<s.size(); i+=2){
    cout << s.at(i);
    if(i+1 == s.size()) break;
   
  }
  
}
