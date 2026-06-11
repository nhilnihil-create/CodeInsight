#include <bits/stdc++.h>
using namespace std;

int main() {
  string S, rS;
  cin >> S;
  rS=S;
  reverse(rS.begin(), rS.end());
  
  int A = S.find("A");
  int rZ = rS.find("Z");
  
  cout << S.size()-A-rZ << endl;
}