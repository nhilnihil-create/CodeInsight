#include <iostream>
#include <string>
using namespace std;

int main(){
  string s;
  cin >> s;
  cout << s.front() << s.size()-2 << s.back();
  return 0;
}