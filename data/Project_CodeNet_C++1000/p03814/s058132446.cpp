#include <iostream>
#include <string>
using namespace std;


int main(){
  string s;
  int a, z;
  
  cin >> s;
  
  for(int i = 0;;i++){
    if(s.at(i) == 'A'){
      a = i;
      break;
    }
  }
  for(int i = s.size() - 1;;i--){
    if(s.at(i) == 'Z'){
      z = i;
      break;
    }
  }
  
  cout << z - a + 1 << endl;
  
  return 0;
}