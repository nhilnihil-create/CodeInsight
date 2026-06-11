#include <iostream>
using namespace std;

int main()
{
  int N, bottuns[100010], bucket[100010] = {0}, target;
  cin >> N;
  for (int i = 0; i < N; i++) cin >> bottuns[i];

  target = bottuns[0];
  bucket[1] = 1;
  for (int i = 1; i < N; i++)
  {
    if (target == 2)
    {
      cout << i << endl;
      return 0;
    }
    if (bucket[target] != 0) break;
    bucket[target] = 1;
    target = bottuns[target - 1];
  }
  cout << -1 << endl;
  return 0;
}
