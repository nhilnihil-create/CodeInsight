#include <bits/stdc++.h>
using namespace std;

int main(){
  string str;
  char c;
  getline(cin, str);
  for(int i = 0; i < str.size(); i++){
    if(str.at(i) == ' '){
      c = str.at(i + 1);
      break;
    }
  }
  cout << 'A' << c << 'C' << endl;
}
