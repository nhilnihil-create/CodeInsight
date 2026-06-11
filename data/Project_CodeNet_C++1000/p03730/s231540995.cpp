#include <bits/stdc++.h>
#define rep(i,a,n) for(int i =a; i<n; i++)
using namespace std;

int main() {
  int A,B,C; cin >> A >> B >> C;
  bool check = false;
  rep(i,0,B+1) if (A * i % B == C) check = true;
  if (check) cout << "YES" << endl;
  else cout << "NO" << endl;
}  