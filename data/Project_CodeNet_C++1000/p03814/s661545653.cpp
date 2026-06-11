#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;

  size_t len = s.find_last_of('Z') - s.find_first_of('A');
  cout << len +1 << endl;
  return 0;
}
