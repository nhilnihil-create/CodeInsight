#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> x(N);
	for (int i = 0; i < N; i++)
		cin >> x[i];

	vector<int> ways(N);
	
	for (int j = 0; j < N; j++)
		ways[j] = 0;
		
	ways[0] = 2;

	long long start = 0;
	for (int i = 2; i < N; i++)
	{
		if (i - (x[i - 1] + 1) / 2 > start)
			start++;
		ways[start]++;
	}

	for (int i = 1; i < N; i++)
		ways[i] += ways[i-1];

	long long result = ways[0];
	for (int j = 1; j < N; j++)
		result = (result * (ways[j] - j)) % 1000000007;

	cout << result;

	return 0;
}