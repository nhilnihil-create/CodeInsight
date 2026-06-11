#include <iostream>
#include <string>
#include <climits>
using namespace std;

bool allCharEquals(string s){
  char awal = s[0];
  for(int i=1; i<s.size(); i++)
    if(s[i] != awal) return false;
  return true;
}

int main() {
  string s;
  cin >> s;

  int ans = INT_MAX;
  for(char ch = 'a'; ch <= 'z'; ch++){
    string temp = s;
    int process = 0;
    while(!allCharEquals(temp)){
      string newString = "";

      for(int i=0; i<temp.size()-1; i++){
        if(temp[i] == ch || temp[i+1] == ch){
          newString += ch;
        }
        else {
          newString += temp[i];
        }
      }

      temp = newString;
      process++;
    }

    ans = min(ans, process);
  }

  cout << ans << endl;
}