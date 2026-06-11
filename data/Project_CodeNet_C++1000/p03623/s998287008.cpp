#include <bits/stdc++.h>
using namespace std;

int main()
{
  int x, a, b, temp1, temp2;

  cin >> x >> a >> b;

  temp1 = a - x;
  if (0 > temp1) {
    temp1 *= -1;
  }
  temp2 = b - x;
  if (0 > temp2) {
    temp2 *= -1;
  }

  if (temp1 < temp2) {
    cout << "A" << endl;
  } else {
    cout << "B" << endl;
  }
}
