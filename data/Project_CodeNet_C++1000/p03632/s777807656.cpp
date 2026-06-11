#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  int st = max(A, C);
  int en = min(B, D);
  cout << max(0, en-st) << endl;
  return 0;
}

