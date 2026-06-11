#include <iostream>
using namespace std;

int main(){
  string str;
  cin >> str;
  int type = 1;
  char c = str[0];
  for(int i=0; i<str.length(); i++){
    if(str[i] != c){
      type++;
      c = str[i];
    }
  }
  cout << type-1 << endl;
  return 0;
}
  
  