#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  
  int A_first;
  int Z_last;
  
  for(int i=0; i<s.size(); i++){
    if(s.at(i) == 'A'){
      A_first = i+1;
      break;
    }
  }
  
  reverse(s.begin(), s.end());
  for(int i=0; i < s.size(); i++){
    if(s.at(i) == 'Z'){
      Z_last = s.size() - i;
      break;
    }
  }
  
  int size = Z_last - A_first + 1;
  
  cout << size << endl;
  
}
