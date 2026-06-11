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
	long long N;
	cin >> N;
	long long * x = new long long[N];
	for (size_t i = 0; i < N; i++)
		cin >> x[i];

	long long* ways = new long long[N];
	
	for (size_t j = 0; j < N; j++)
		ways[j] = 0;
		
	ways[0] = 2;

	long long start = 0;
	for (size_t i = 2; i < N; i++)
	{
		if ((x[i-1]+1)/2 < i - start)
			start++;
		ways[start]++;
	}

	for (size_t i = 1; i < N; i++)
	{
		ways[i] += ways[i-1];
	}

	long long result = ways[0];
	for (long long j = 1; j < N; j++)
	{
		if (ways[j] >= j)
			result = (result * (ways[j] - j)) % 1000000007LL;
	}

	cout << result;

	return 0;
}