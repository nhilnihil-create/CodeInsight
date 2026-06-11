#include <iostream>
#include <string>
using namespace std;

int main() {
  string raw;
  cin >> raw;
  string initial = raw.substr(0, 1);
  string last = raw.substr(raw.length() - 1, 1);
  string middle = raw.substr(1, raw.length() - 2);
  cout << initial + to_string(raw.length() - 2) + last << endl;
}
