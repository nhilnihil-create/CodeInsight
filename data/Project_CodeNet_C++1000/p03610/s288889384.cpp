#include <bits/stdc++.h>
using namespace std;


int main(){

  string s;
  cin >> s;

  string odd;
  int counter = 0;
  while(s[counter]){
    if(counter%2 == 0){
        odd.push_back(s[counter]);
    }
    ++counter;
  }

  cout << odd << endl;

  return 0; 
}