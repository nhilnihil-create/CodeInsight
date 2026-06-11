#include<iostream>
using namespace std;
#include<algorithm>
#include<cstring>
#include<string>
#include<stdio.h>
#include<map>
#include<vector>
#include<cmath>
#include<iomanip>
#include<queue>
#include<stack>
#include<set>
#define maxn 1000005
#define INF 1e9
#define ll long long
int n, a[205];
int  main()
{
	while (cin >> n) {
		for (int i = 0; i < 2 * n; i++)
			cin >> a[i];
		sort(a, a + 2 * n);
		int sum = 0;
		for (int i = 0; i < 2 * n; i += 2)
			sum += a[i];
		cout << sum << endl;
	}
	return 0;
}