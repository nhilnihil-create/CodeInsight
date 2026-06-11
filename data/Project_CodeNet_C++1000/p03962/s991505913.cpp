#include <bits/stdc++.h>
using namespace std;

signed main(){
	int a, b, c, ans = 0, i;
	scanf("%d%d%d", &a, &b, &c);
	vector<int> count(101, 0);
	count[a] = 1;
	count[b] = 1;
	count[c] = 1;
	for(i = 0; i <= 100; i++){
		ans += count[i];
	}
	printf("%d\n", ans);
	return 0;
}