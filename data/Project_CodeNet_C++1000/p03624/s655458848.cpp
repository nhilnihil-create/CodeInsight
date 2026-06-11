#include <iostream>
using namespace std;
int main() {
  string s;
  cin >> s;
  bool b[26]= {false};
  int l = s.size();
  for (int i=0; i<l; i++){ 
   b[(s[i]-'a')]=true;
  } 
  for (int i=0; i<26; i++) {
    if (!b[i])  {
      cout << char (i + 'a') <<endl;
      return 0;
    }
  }
  cout << "None" <<endl;
}