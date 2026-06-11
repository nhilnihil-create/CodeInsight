#include <bits/stdc++.h>
using namespace std;
#define fr(i, j, k) for(register int i = j; i <= k; ++i)
#define gc ch = getchar()
int read(){
	int ret = 0, f = 1; char gc;
	while(!isdigit(ch) && (ch ^ '-'))gc;
	if(!(ch ^ '-'))f = -1, gc;
	while(isdigit(ch)){ret = (ret << 3) + (ret << 1) + (ch ^ '0'), gc;}
	return ret * f;
}
#undef gc
const int maxn = 1e5 + 10;
const int inf = 2147483647;
int n;
int a[maxn << 1];
int minn = inf, maxx = -inf;
bool small(int i, int j, int x){
	return a[i] <= x && a[j] <= x;
}
bool big(int i, int j, int x){
	return a[i] > x && a[j] > x;
} 
bool check(int x){
	for(int i = 0; i < n - 1; ++i){
		if(big(n + i, n + i + 1, x) || big(n - i, n - i - 1, x))return 0;
		if(small(n + i, n + i + 1, x) || small(n - i, n - i - 1, x))return 1;
	}
	return small(1, 1, x);
}
int main(){
	n = read();
	fr(i, 1, 2 * n - 1){
		a[i] = read();
		minn = min(a[i], minn);
		maxx = max(a[i], maxx);
	}
	int l = minn, r = maxx, ans = 0;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(check(mid)){
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout<<ans<<endl;
	return 0;
}