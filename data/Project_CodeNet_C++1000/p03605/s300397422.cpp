#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  bool contains = std::to_string(N).find('9') != std::string::npos;

  cout << (contains ? "Yes" : "No") << endl;
}