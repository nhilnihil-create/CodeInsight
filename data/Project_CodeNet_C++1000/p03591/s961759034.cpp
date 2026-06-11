#include<bits/stdc++.h>
using namespace std;

bool check(string s){
  if(s.size() < 4){
    return false;
  }
  return s.substr(0, 4) == "YAKI";
}

int main(){
  string s;
  cin >> s;
  if(check(s)){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}