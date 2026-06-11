#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  string uni_s = s;

  uni_s.erase(unique(uni_s.begin(),uni_s.end()), uni_s.end());

  if(uni_s.size() == s.size()) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }
}