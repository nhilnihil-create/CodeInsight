#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
  string s;
  cin >> s;
  string a = "";
  for(int i = 0; i < s.length(); i++){
    if (i%2 == 0){
      a += s.at(i);
    }
  }
  cout << a << endl;
}
