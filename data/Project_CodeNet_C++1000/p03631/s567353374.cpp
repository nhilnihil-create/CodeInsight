#include <bits/stdc++.h>
using namespace std;

int main() {
  string N, Nreverse;
  cin >> N;
  
  reverse_copy(N.begin(), N.end(), back_inserter(Nreverse));
  
  if(N==Nreverse) cout << "Yes" << endl;
  else cout << "No" << endl;
}