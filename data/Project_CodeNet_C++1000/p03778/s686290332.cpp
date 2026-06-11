#include <bits/stdc++.h>
using namespace std;

int main() {
  int W, a, b;
  cin >> W >> a >> b;
  int diff;
  if (abs(a-b)<=W)
    diff = 0;
  else if(b>a)
    diff = b-(a+W);
  else
    diff = a-(b+W);
  cout << diff << endl;
}