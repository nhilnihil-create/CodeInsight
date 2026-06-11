#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  string t = "YAKI";
  
  bool flag = 1;
  if (s.size() < 4) cout << "No" << endl;
  else{
    for(int i = 0; i < 4; i++){
      if(s.at(i) != t.at(i)) flag = 0;
    }
         if(flag == 1) cout << "Yes" << endl;
         else cout << "No" << endl;
  }


}