#define _CRT_SECURE_NO_WARNINGS

#include <unordered_map>
#include <string>
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#define MAXN 1005
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define PI acos(-1)
typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int n, a[100005];

int cmp(int a, int b) {
	return a > b;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1,cmp);
	int i = 1, j;
	while (a[i] >= i) ++i;
	--i;
	j = i + 1;
	while (a[j] == i) ++j;
	--j;
	if ((a[i] - i) % 2 || (j - i) % 2)
		cout << "First" << endl;
	else
		cout << "Second" << endl;
}