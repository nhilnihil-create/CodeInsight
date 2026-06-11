#include <bits/stdc++.h>
using namespace std;

int cnt[3];

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if(x % 4 == 0) cnt[0]++;
		else if(x % 2 == 0) cnt[1]++;
		else cnt[2]++;
	}
	if(cnt[0] >= n / 2) printf("Yes\n");
	else if(cnt[0] >= cnt[2]) printf("Yes\n");
	else printf("No\n");
}
