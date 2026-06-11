#include <iostream>
#include <cstring>
using namespace std;

bool check(string t){
  bool flag = true;
  for(int i = 1; i < t.size(); i++){
    if(t[i] != t[i-1]){
      flag = false;
      break;
    }
  }
  return flag;
}

void solve(string s){
  int steps = 0, result = 1e9; // 10^9
  string t, newT; 

  for(int i = 0; i < s.size(); i++){
    char c = s[i];
    steps = 0; 
    t = s;
    while(check(t) == false){
      newT = "";
      for(int i = 0; i < t.size()-1; i++){
        if(t[i] == c || t[i+1]==c){
          newT += c;
        }
        else newT += t[i];
      }
      t = newT;
      steps++;
    }
    // Find the min
    result = min(result, steps);
  }
  cout << result << endl; 
}

int main(){
  string s;
  cin >> s; 

  solve(s);
}