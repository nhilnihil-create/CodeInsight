#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef vector<int> vec1;
typedef vector<string> vec2;
typedef vector<double> vec3;

int main() {
  
  string s;
  cin >> s;

  int a = s.size()-2;

  cout << s.at(0) << a << s.at(s.size()-1) << endl;
}