#include <iostream>
using namespace std;

bool allLettersAreEqual(string s){
  for(int i=0; i<s.size(); i++){
    if(s[i] != s[0]) return false;
  }
  return true;
}

int solve(string s){

  int result = 1e9;
  for(int i = 0; i < s.size(); i++){
    char target = s[i];
    
    int steps = 0;
    string t = s;
    while(!allLettersAreEqual(t)) {
      string tnew = "";
      for(int i=0; i<t.size()-1; i++){
        if(t[i] == target || t[i+1] == target) {
          tnew += target;
        }
        else tnew += t[i];
      }

      t = tnew;
      steps++;
    } 

    result = min(result, steps);
  }

  return result;
}

int main() {
  string s;
  cin >> s;
  cout << solve(s) << endl;
}