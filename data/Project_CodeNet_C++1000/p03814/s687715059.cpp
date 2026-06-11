#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s;
  cin >> s;
 
  int numa=0;
  int numz=0;
  int i=0;
  int j=s.size()-1;
  
  while(numa==0){
    if(s[i]=='A'){
      numa++;
    }
    i++;
  }
  
  while(numz==0){
    if(s[j]=='Z'){
      numz++;
    }
    j--;
  }
  
  cout << j-i+3 << endl;
  
}
