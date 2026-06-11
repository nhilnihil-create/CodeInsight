#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
	int n;
	scanf("%d", &n);
	vector<int> l(n * 2);
	rep(i, n * 2) scanf("%d", &l[i]);
	sort(l.begin(), l.end());
	int count = 0;
	for(int i = 0; i < (n * 2); i = i + 2) {
		count += l[i];
	}
	printf("%d\n", count);
	return 0;
}