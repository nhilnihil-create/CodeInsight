#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string str,str2;
  int n;
  cin >> str;
  str2 = str + str.at(11);
  str2.at(4) = ' ';
  
  for(int i = 0; i < 4; i++){
   str2.at(i) = str.at(i);
  }
 
 for(int i =5; i < 12; i++){
   str2.at(i) = str.at(i - 1) ;

  }
    cout << str2 << endl;
}