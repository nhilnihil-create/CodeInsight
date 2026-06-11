#include<bits/stdc++.h>
#define Rint register int
using namespace std;
const int N = 200003;
int n, a[N], b[N];
inline bool check(int x){
	for(Rint i = 1;i < (n << 1);i ++) b[i] = (a[i] >= x);
	for(Rint i = 0;i < n - 1;i ++){
		if(b[n + i] == b[n + i + 1]) return b[n + i];
		if(b[n - i] == b[n - i - 1]) return b[n - i];
	}
	return b[1];
}
int main(){
	scanf("%d", &n);
	for(Rint i = 1;i < (n << 1);i ++) scanf("%d", a + i);
	int l = 1, r = 2 * n - 1, mid, ans = 0;
	while(l <= r){
		mid = l + r >> 1;
		if(check(mid)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	printf("%d", ans);
}