#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>

using std::map;
using std::max;
using std::min;
int a[100005];
map<int, int> s;

int main(void)
{
	int N, T,profit = 0,jiujimin = 0x7fffffff;
	scanf("%d%d", &N, &T);
	for (int i = 0; i < N; ++i)
		scanf("%d", &a[i]);
	for (int i = 0; i < N; ++i)
	{
		if (a[i] < jiujimin)
			jiujimin = a[i];
		else
		{
			if (a[i] - jiujimin > profit)
			{
				profit = a[i] - jiujimin;
				++s[profit];
			}
			else if (a[i] - jiujimin == profit)
				++s[profit];
		}

	}
	if (!profit)
		printf("%d", N);
	else
		printf("%d",s[profit]);
}