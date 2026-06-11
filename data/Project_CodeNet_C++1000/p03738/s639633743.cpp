#include <iostream>
#include <string>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  if(s.size() > t.size()) {
    cout << "GREATER\n";
    return 0;
  } else if(s.size() < t.size()) {
    cout << "LESS\n";
    return 0;
  } else {
    int ss = s.size();
    for(int i = 0; i < ss; i++) {
      if(s[i] > t[i]) {
        cout << "GREATER\n";
        return 0;
      } else if(s[i] < t[i]) {
        cout << "LESS\n";
        return 0;
      }
    }
    cout << "EQUAL\n";
    return 0;
  }
}