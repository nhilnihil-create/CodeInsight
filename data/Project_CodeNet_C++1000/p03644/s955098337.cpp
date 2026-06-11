/* Break Number */

#include <iostream>
using namespace std;

int	main()
{
  int	n, sq = 1;
  
  cin >> n;
  for (; sq <= n; sq *= 2)
  {}
  
  cout << sq / 2 << endl;
  return (0);
}