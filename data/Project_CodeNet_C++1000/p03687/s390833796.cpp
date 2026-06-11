#include <iostream>
using namespace std;

int getMax(string s, char letter){
  int result = 0;
  s = letter + s + letter;
  int left = 0;
  for(int right=1; right < s.size(); right++){
    if(s[right] == letter){
      result = max(result, right - left - 1);
      left = right;
    }
  }
  return result;
}


int main(){
  string s;
  cin >> s;
  int ans = 1e6;
  for(char letter = 'a'; letter <= 'z'; letter++){
    ans = min(ans, getMax(s, letter));
  }
  cout << ans << endl;
  return 0;
}
