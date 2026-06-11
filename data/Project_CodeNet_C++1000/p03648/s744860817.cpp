#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdio.h>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<time.h> 
#define debug(a) cout << "*" << a << "*" << endl
#define ls	(k << 1)
#define rs	((k << 1) | 1)
#define mid	((l + r) >> 1)
using namespace std;
typedef long long ll;
ll a[55], m, n;
int main()
{
	while (~scanf("%lld", &m))
	{
		//m = low(1, m, m);
		memset(a, 0, sizeof(a)); 
		printf("50\n");
		n = m % 50;
		m /= 50;
		for (int i = 0; i < n; i++)	a[i] = 50;
		if (m)
			for (int i = 0; i < 50; i++) a[i] += (49 - n + m);
		for (int i = 0; i < 50; i++)	printf("%lld%c", a[i], i == 49 ? '\n' : ' ');
	} 
}