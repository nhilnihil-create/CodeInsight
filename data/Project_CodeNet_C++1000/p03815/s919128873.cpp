#include <iostream>

using namespace std;

int main()	{
  long long ways;
  long long x;
  cin >> x;
  ways = 2 * (x / 11);
  int remaining = (x % 11);
  if (remaining > 0 && remaining <= 6)	{
    ways++;
  }
  else if (remaining > 6)
    ways+=2;
  cout << ways;
  cout << endl;
  return 0;
}