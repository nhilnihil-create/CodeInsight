#include <iostream>

using namespace std;

typedef long long ll;

const ll C = 5e8;
const int MAX_N = 2e4 + 5;

ll target [MAX_N];
ll A [MAX_N];
ll B [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    int pi;
    cin >> pi;

    target[pi] = 2 * C + i;
  }

  A[n + 1] = C;
  B[n + 1] = C;
  for (int i = n; i >= 1; i--) {
    ll amax = A[i + 1] - 1;
    ll bmin = B[i + 1] + 1;

    if (target[i] - amax >= bmin) {
      A[i] = amax;
      B[i] = target[i] - amax;
    } else {
      A[i] = target[i] - bmin;
      B[i] = bmin;
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << A[i] << " ";
  }
  cout << endl;
  for (int i = 1; i <= n; i++) {
    cout << B[i] << " ";
  }
  cout << endl;
}
