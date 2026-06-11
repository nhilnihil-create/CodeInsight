#include<bits/stdc++.h>
using namespace std;
int main() {
  string a, b, c; cin >> a >> b >> c;
  cout << (char)(a.at(0) + ('A' - 'a')) << (char)(b.at(0) + ('A' - 'a')) << (char)(c.at(0) + ('A' - 'a')) << endl;
}