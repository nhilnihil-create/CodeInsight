#include <iostream>

using namespace std;

int main()	{
  int a, b;
  cin >> a >> b;
  int x[a];
  for (int i = 0; i < a; i++)	{
  	cin >> x[i];
  }
  long long moves = 0;
  if (x[0] > b)	{
    moves += x[0] - b;
    x[0] = b;
  }
  for (int i = 0; i < a - 1; i++)	{
    if (x[i + 1] + x[i] > b)	{
      moves += x[i + 1] + x[i] - b;
	  x[i + 1] -= x[i + 1] + x[i] - b;
      if (x[i + 1] < 0)	{
        x[i] += x[i + 1];
        x[i + 1] = 0;
      }
    }
  }
  
  cout << moves << endl;
  return 0;
}
