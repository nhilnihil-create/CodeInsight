#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
  string s;
  cin >> s;
  int before = s.size();
  sort(s.begin(), s.end());
  s.erase(unique(s.begin(), s.end()), s.end());
  if(before == s.size()){
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }
  return 0;
}
