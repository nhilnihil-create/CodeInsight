#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
	ll mok;
	scanf("%lld", &mok);
	vector<ll>t;
	for (int i = 0; i < 50; i++)t.push_back(49 + mok / 50);
	for (int i = 0; i < mok % 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			if (i != j)t[j]--;
			else t[j] += 50;
		}
	}
	printf("50\n");
	for (int i = 0; i < 50; i++)printf("%lld\n", t[i]);
}