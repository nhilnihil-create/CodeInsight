#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;

int main() {
string O,E;
cin >> O >> E;
for(int i = 0;i < O.size();i++) {
  if (i == E.size()) cout << O.at(i);
  else cout << O.at(i) << E.at(i);
}
cout << endl;


return 0;
}