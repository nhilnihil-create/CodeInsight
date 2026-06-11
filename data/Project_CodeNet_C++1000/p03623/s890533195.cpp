#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c;cin>>a>>b>>c;
  if (abs(a-b) < abs(a-c)) cout << 'A' << endl;
  else cout << 'B' << endl;
}