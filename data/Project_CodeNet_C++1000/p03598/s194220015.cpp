#include <bits/stdc++.h>
using namespace std;
 
int main(void)
{
	int N, K, i, x, sumdistance;

  	sumdistance = 0;
	cin >> N >> K;
	for (i = 0; i < N; ++i)
    {
      cin >> x;
      if ( x < K - x)
      {
        sumdistance += x *2;
      }
      else
      {
        sumdistance +=(K - x) * 2;
      }
    }
	cout << sumdistance << endl;
	return (0);
}