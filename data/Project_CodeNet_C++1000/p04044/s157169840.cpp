#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, l;
  cin >> n >> l;
  vector<string> vec;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    vec.push_back(str);
  }
  sort(vec.begin(), vec.end());
  for (auto i = vec.begin(); i != vec.end(); i++) cout << *i;
  cout << endl;
}