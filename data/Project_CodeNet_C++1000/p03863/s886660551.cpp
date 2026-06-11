#include <iostream>
#include <string>

using namespace std;

int main() {
  string str;
  cin >> str;
  bool odd = str.size() % 2;
  bool same = str.front() == str.back();
  
  if (odd^same) {
    cout << "First" << endl;
  } else {
    cout << "Second" << endl;
  }
  
  return 0;
}