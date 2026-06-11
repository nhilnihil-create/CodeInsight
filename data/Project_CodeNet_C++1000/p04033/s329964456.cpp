#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(int)(a); i++)
typedef long long ll;

int main()
{
  int a, b; cin >> a >> b;

  if ((a <= 0 && 0 <= b) || a == 0 || b == 0) {
    cout << "Zero" << endl;
    return 0;
  } else if (0 < a) {
    cout << "Positive" << endl;
    return 0;
  }

  if ((b-a) % 2 == 0) {
    cout << "Negative" << endl;
  } else {
    cout << "Positive" << endl;
  }

  return 0;
}
