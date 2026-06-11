#include <bits/stdc++.h>
using namespace std;

long long int kotae(string s) {

  if (s.size() == 1) {
    return stoll(s);
  }

  long long int sum = stoll(s);
  for (int i = 1; i < s.size(); i++) {
    sum += kotae(s.substr(0, i)) + stoll(s.substr(i)) * pow(2, i - 1);
  }
  return sum;
}

int main() {
  string s;
  cin >> s;

  cout << kotae(s) << endl;
}
