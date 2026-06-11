#include <iostream>
using namespace std;

int main()
{
  int N;
  const int devide = 1000000007;
  long long int power;

  cin >> N;

  power = 1;
  for (int i = 1; i <= N; i++)
    power = (power * i) % devide;
  cout << power << endl;

  return 0;
}
