#include <iostream>
#include <string>
using namespace std;

int main(){
  string s;
  cin >> s;
  int first_A = 0;
  int last_Z = s.size() - 1;
  for(int i = 0; i < s.size(); i++){
    if(s.at(i) == 'A'){
      first_A = i;
      break;
    }
  }
  for(int i = s.size() - 1; i > 0; i--){
    if(s.at(i) == 'Z'){
      last_Z = i;
      break;
    }
  }
  cout << last_Z - first_A + 1;
  return 0;
}