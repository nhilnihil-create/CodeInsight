#include<bits/stdc++.h>
using namespace std;

int main(void) {
  int a, b, c;
  cin >> a >> b >> c;
  set<int> s{a, b, c};
  cout << s.size();
}