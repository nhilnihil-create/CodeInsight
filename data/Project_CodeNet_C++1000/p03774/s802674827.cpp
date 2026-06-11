#include <iostream>
#include <cmath>

using namespace std;

/*long long abs(long long x)	{
  return (x <= 0 ? -x : x);
}*/

int main()	{
  int n, m;
  cin >> n >> m;
  long long sx[n] = {0}, sy[n] = {0}, cx[m] = {0}, cy[m] = {0};
  for (int i = 0; i < n; i++)	
    cin >> sx[i] >> sy[i];
  for (int i = 0; i < m; i++)
    cin >> cx[i] >> cy[i];
  long long checkpoint[n] = {0};
  for (int i = 0; i < n; i++)	{
    for (int j = 0; j < m; j++)	{
      if (abs(sx[i] - cx[checkpoint[i]]) + abs(sy[i] - cy[checkpoint[i]]) > abs(sx[i] - cx[j]) + abs(sy[i] - cy[j]))	{
      	checkpoint[i] = j;
      }
    }
    cout << checkpoint[i] + 1 << endl;
  }
  return 0;
}