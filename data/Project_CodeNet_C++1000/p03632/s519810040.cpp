#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C,D;
  cin >> A >> B >> C >> D;
  int lower = max(A,C);
  int upper = min(B,D);
  if (lower<upper) cout << upper-lower<<endl;
  if (upper<=lower) cout << 0 <<endl;
}
