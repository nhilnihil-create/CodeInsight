#include <bits/stdc++.h>

#define PI 3.14159265358979323846264338327950288419

using namespace std;

int n;
int a[100005];
int b[100005];

long long cur_inc, ans;

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d %d", &a[i], &b[i]);
	}
	for(int i = n; i >= 1; i--){
		int cur_mod = (a[i] + cur_inc) % b[i];
		if(cur_mod > 0){
			cur_inc += (b[i] - cur_mod);
			ans += (b[i] - cur_mod);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
