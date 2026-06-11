#include <iostream>
#include <string>
using namespace std;

int main(){
  string s;
  int flag = 1;
  cin >> s;
  for(int i = 0; i < s.size(); i++){
    if(s[i] == 'b'){
      if(s[s.size()-(i+1)] != 'd'){
        flag = 0;
        break;
      }
    }
    if(s[i] == 'q'){
      if(s[s.size()-(i+1)] != 'p'){
        flag = 0;
        break;
      }
    }
    if(s[i] == 'd'){
      if(s[s.size()-(i+1)] != 'b'){
        flag = 0;
        break;
      }
    }
    if(s[i] == 'p'){
      if(s[s.size()-(i+1)] != 'q'){
        flag = 0;
        break;
      }
    }
  }
  if(flag)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
