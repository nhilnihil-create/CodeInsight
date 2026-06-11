#include <bits/stdc++.h>
using namespace std;
 
int main(void)
{
	int N, l, r, i, sum;
  	
    sum = 0;
	cin >> N;
	for (i = 0; i < N; ++i)
    {
      cin >> l >> r;
      sum  += r - l + 1;
    }
	cout << sum << endl;
    return (0);
}