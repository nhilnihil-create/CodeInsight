#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;


int main(){
  string s;
  cin >> s ;
  
  for (int i=0; i<s.size(); i++){
    for (int j=i+1; j<s.size(); j++){
      if (s[i] == s[j]){
        cout << "no";
        return 0;
      }
    }
  }
  cout << "yes";
}