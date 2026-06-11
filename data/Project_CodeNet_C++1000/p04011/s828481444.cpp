#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int i, N, K, X, Y, cost = 0;

	cin >> N >> K >> X >> Y;
	for (i = 0; i < N; i++)
	{
		if (i < K)
		{
			cost += X;
		}
		else
		{
			cost += Y;
		}
	}
	cout << cost;
}