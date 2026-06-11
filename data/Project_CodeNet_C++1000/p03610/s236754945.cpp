#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  cin >> str;
  string result = "";
  for(int i = 0; i < str.size(); i += 2) {
    result += str.at(i);
  }
  cout << result << endl;
}