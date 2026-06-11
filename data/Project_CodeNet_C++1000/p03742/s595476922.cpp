
#include <bits/stdc++.h>

#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll X, Y;

int main() {
  cin >> X >> Y;

  if (X == Y || Y == X+1 || Y == X-1) {
    cout << "Brown" << endl;
  } else {
    cout << "Alice" << endl;
  }

  return 0;
}
