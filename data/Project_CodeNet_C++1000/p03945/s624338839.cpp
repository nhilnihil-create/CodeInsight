#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,int>;
using ll=long long;

int main() {
  string S;
  cin >> S;
  int m=0;
  for (int i=0; i<S.size()-1; i++) {
    if (S[i]!=S[i+1]) {m++;}
  }
  cout << m << endl;
}