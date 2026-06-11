#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

ifstream fin("../data.txt");

int w, h;
string s;

int main() {

  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    cin >> s;
    cout << s << "\n" << s << "\n";
  }

  return 0;
}
