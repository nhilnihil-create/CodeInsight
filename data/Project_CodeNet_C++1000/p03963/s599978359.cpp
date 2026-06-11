#include <iostream>
using namespace std;

int main()
{
  int N, K, res;

  cin >> N >> K;
  res = K;
  for (int i = 1; i < N; i++)
    res *= K - 1;
  cout << res << endl;
}
