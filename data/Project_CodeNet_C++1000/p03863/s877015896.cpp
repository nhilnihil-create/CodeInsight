#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int n = s.size();
  if((s.at(0) == s.at(n-1) && n % 2 != 0) || (s.at(0) != s.at(n-1) && n % 2 == 0)){
    cout << "Second" << endl;
  }
  else{
    cout << "First" << endl;
  }
}