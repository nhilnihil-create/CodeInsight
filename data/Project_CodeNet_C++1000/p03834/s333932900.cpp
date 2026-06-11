#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<char> str(19);
  for(int i = 0; i < 19; i++){
    cin >> str.at(i);
  }
  str.at(5) = ' ';
  str.at(13) = ' ';
  for(int i = 0; i < 19; i++){
    cout << str.at(i);
  }
  cout << endl;
  return 0;
}
