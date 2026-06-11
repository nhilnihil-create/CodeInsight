#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<char> str(19);
  for(int i = 0; i < 19; i++){
    cin >> str.at(i);
  }
  for(int i = 0; i < 5; i++){
    cout << str.at(i);
  }
  cout << " ";
  for(int i = 6; i < 13; i++){
    cout << str.at(i);
  }
  cout << " ";
  for(int i = 14; i < 19; i++){
    cout << str.at(i);
  }
  cout << endl;
  return 0;
}
