#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <fstream>
#include <unordered_map>

using namespace std;

ifstream fin("../data.txt");

vector<string> v = {"eraser", "erase", "dreamer", "dream"};
string s;
int pos;

int main() {

  getline(cin, s);
  for (int i = 0; i < 4; i++) {
    while((pos = s.find(v[i])) != -1) {
      s.replace(pos, v[i].size(), "");
    }
  }
  if(s == "") {
    cout << "YES";
  } else cout << "NO";
  return 0;
}
