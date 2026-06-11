#include <iostream>
using namespace std;

int main()
{
  int A, B, C, tmp;

  cin >> A >> B >> C;
  tmp = A;
  for (int i = 0; i < B; i++)
  {
    if (tmp % B == C)
    {
      cout << "YES" <<  endl;
      return 0;
    }
    tmp += A;
  }
  cout << "NO" << endl;
  return 0;
}
