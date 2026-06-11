#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >>S;
  int X = S.size();
  
  cout << S.at(0)<<X-2<<S.at(X-1);
}
