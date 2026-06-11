#include <iostream>
#include <string>

using namespace std;

int main(){
  string s;
  cin >> s;

  int n = s.size();
  int len = 0;
  for(int i = 0; i < n-1; i++){
    s.erase(s.size() -1);
    len = s.size();
    if(len %2 != 0) {
      continue;
    } else if (s.substr(0, len/2) == s.substr(len/2, len)) {
      break;
    }
  }
  cout << len << endl;
  return 0;
}

