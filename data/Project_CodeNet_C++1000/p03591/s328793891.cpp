#include<bits/stdc++.h>
using namespace std;

int main (){
  string s;
cin >> s;
 if(s.size()<4){
   cout << "No" << endl;
   return 0;
 }
if(s.at(0) != 'Y'||s.at(1) != 'A'||s.at(2) != 'K'||s.at(3) != 'I'){
  cout << "No" << endl;
  return 0;
}
else cout << "Yes" << endl;
}
