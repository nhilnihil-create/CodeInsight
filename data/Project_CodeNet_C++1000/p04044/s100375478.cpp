#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

ifstream fin("data.txt");

vector<string> v;
string x;
int n, l;

int main() {

  cin >> n >> l;
  cin.ignore();
  for (int i = 0; i < n; i++) {
    getline(cin, x);
    v.push_back(x);
  }

  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    cout << v[i];
  }

  return 0;
}
