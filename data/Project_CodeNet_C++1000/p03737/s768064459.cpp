#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define ll long long
using namespace std;

int main() {
  string s, t, r;
  cin >> s >> t >> r;
  char ss = s[0] - 0x20, tt = t[0] - 0x20, rr = r[0] - 0x20;
  cout << ss << tt << rr << "\n";
}