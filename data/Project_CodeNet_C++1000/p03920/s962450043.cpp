#include <iostream>
#include <cmath>

using namespace std;

int
main()
{
  int N;
  cin >> N;

  int s = sqrt(2.0 * N);
  while (s * (s + 1) / 2 < N)
    ++s;
  int r = s * (s + 1) / 2 - N;

  for (int i = 1; i < r; ++i)
    cout << i << "\n";
  for (int i = r + 1; i <= s; ++i)
    cout << i << "\n";
  return 0;
}
