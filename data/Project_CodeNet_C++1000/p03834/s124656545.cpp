#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  string s;
  cin >> s;

  cout << s.substr(0, 5) + " " + s.substr(6, 7) + " " + s.substr(14)<< "\n";
}
