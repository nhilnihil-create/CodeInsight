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
	int i, j, N;
	cin >> N;
	vector<int> num(N);
	for (i = 0; i < N; i++)
	{
		cin >> num[i];
	}
	vector<int> kouho(3);
	vector<int> cost(3);
	for (i = 0; i < 3; i++)
	{
		kouho[i] = accumulate(num.begin(), num.end(), 0) / N + i - 1;
	}
	for (i = 0; i < 3; i++)
	{
		int tmp = 0;
		for (j = 0; j < N; j++)
		{
			tmp += pow(kouho[i] - num[j], 2);
		}
		cost[i] = tmp;
	}
	cout << *min_element(cost.begin(), cost.end());
}