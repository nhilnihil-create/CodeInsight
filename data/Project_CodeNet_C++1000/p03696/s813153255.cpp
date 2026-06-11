#include <iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  string str;
  cin >> str;
  int left = 0;
  int right = 0;
  for(int i=0; i<n; i++){
    if(str[i] == '('){
      left++; 
    }else{
      if(left > 0) left--;
      else right++;
    }
  }
  string leftStr = "";
  string rightStr = "";
  for(int i=0; i<right; i++) leftStr += "(";
  for(int i=0; i<left; i++) rightStr += ")";
  cout << leftStr + str + rightStr << endl;
  return 0;
}