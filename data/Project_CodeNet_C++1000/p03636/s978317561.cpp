#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
  string s;
  cin >> s;
  int x = s.size()-2;
  cout << s.front() << to_string(x) << s.back() << endl;
  return 0;
}
