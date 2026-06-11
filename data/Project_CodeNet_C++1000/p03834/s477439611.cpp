#include <iostream>
using namespace std;
int main(){
  string s; cin >> s;
  for(int i = 0; i < s.size(); i++){
    char moji = s.at(i);
    if(moji == ',')
      cout << " ";
    else
      cout << moji;
  }
}