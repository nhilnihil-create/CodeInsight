/************************************************
*Author        :  Jack
*Created Time  :  2019.11.07.21:08
*Mail          :  724033213@qq.com
*Problem       :  AT2165
*Extra         :  
************************************************/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int t[maxn << 1], n;
void read(int & x) {
	x = 0; int f = 1;
	char ch = getchar();
	while(!isdigit(ch)) {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(isdigit(ch)) {
		x = x* 10 + ch - '0';
		ch = getchar();
	}
}
bool O(int x, int y) {
	if(x == 1 && y == 1) return 1;
	return 0;
}
bool Z(int x, int y) {
	if(x == 0 && y == 0) return 1;
	return 0;
}
bool check(int dat) {
	int a[maxn << 1] = {0};
	for(int i = 1;i <= n * 2 - 1;i ++) {
		a[i] = t[i] >= dat;
	}
//	cout << dat << " " ;
//	for(int i = 1;i <= n * 2 - 1;i ++) {
//		cout << a[i] << " " ;
//	}
//	cout << endl;
	for(int len = 0;len < n;len ++) {
		if(O(a[n + len], a[n + len + 1]) || O(a[n - len], a[n - len - 1])) return 1;
		if(Z(a[n + len], a[n + len + 1]) || Z(a[n - len], a[n - len - 1])) return 0;
	}
	return a[1];
}
int main() {
//    freopen("AT2165.in","r",stdin);
//    freopen("AT2165.out","w",stdout);
	read(n);
	for(int i = 1;i <= n * 2 - 1;i ++) read(t[i]);   
	int l = 0, r = n * 2 - 1, ans;
	while(l <= r) {
		int mid = l + r >> 1;
		if(check(mid)) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << ans << endl;
	return 0;
}
