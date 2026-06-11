#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;
  if (s.size() > 2){
    cout << s.at(0) << s.size() - 2 << s.at(s.size() - 1) << endl;
  }
  else cout << s << endl;
}