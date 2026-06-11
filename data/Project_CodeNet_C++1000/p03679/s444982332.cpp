#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll X, A, B;
  cin >> X >> A >> B;

  if(A - B >= 0) { cout << "delicious"; return 0; }

  if(B - A <= X) cout << "safe";
  else cout << "dangerous"; 
 return 0;
}

