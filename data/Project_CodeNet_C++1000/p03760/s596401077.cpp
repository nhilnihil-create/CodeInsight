#include <bits/stdc++.h>
#define rep(i,a,n) for (int i =a; i<n; i++)
using namespace std;

int main() {
  string O,E; cin >> O >> E;
  rep(i,0,E.size()) {
    cout << O[i];
    cout << E[i];
  }
  if (O.size() != E.size()) cout << O[O.size()-1] << endl;
  cout << endl;
}