
#include <iostream>
using namespace std;

int main()
{
  int A, B;
  cin >> A >> B;
  cout << (((0 == A%3) || (0 == B%3) || (0 == (A + B)%3)) ? "Possible" : "Impossible");
  return 0;
}
