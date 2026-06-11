#include <bits/stdc++.h>
using namespace std;

int main(void){
   
  string s;
  cin >> s;
  int len = s.size();
  for(int i=0;i<len;i++){
      if(s[i] == ',') s[i] = ' ';
      cout << s[i];
  }
  cout <<endl;
}