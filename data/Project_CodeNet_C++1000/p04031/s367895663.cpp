#include <iostream>
#include <cmath>
#include <climits>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
#pragma warning(disable: 4996)

int main()
{
	int N;
	int ret;

	ret = scanf("%d", &N);

	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		ret = scanf("%d", &v[i]);
	}

	int sum = accumulate(v.begin(),v.end(),0);
    double average = (double)sum/N;
    int average_int = round(average);

	int result = 0;
	for (int i = 0; i < N; i++) {
		result += pow((v[i] - average_int), 2);
	}

	printf("%d\n", result);
	return 0;
//	std::cout << "Hello World!\n"; 
}