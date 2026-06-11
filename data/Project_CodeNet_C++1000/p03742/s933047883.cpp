#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
int main()
{
	long long x, y, z;
	scanf("%lld%lld", &x, &y);
	if (x > y) swap(x, y);
	if (y - x <= 1)
		printf("Brown\n");
	else
		printf("Alice\n");
	return 0;
}