#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int num;
	scanf("%d", &num);
	int m = 0, s = 0;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		z--;
		if (m == 1)m = 0;
		else if (i == z)s++, m = 1;
	}
	printf("%d\n", s);
}