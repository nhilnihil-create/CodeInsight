//#include "std_lib_facilities.h"
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;

int main() {
	int n;
	scanf("%d", &n);
	int arr[n + 1];
	int vis[n + 1] = { 0 };
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	int ans = 0, pos = 1;
	while (pos != 2) {
		if (vis[pos])
			return printf("-1\n"), 0;
		vis[pos] = 1;
		pos = arr[pos];
		ans++;

	}

	printf("%d\n", ans);

}

