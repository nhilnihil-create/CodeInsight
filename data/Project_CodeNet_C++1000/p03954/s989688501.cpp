#include<cstdio>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;
template <typename T>
void read(T &x) {
	x = 0;int f = 1;
	char c = getchar();
	for (;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for (;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x *= f;
}
const int N = 2000050;
int a[N], n;
inline bool sm(int i,int k) {
	return a[i] < k && a[i+1] < k;
}
inline bool bi(int i,int k) {
	return a[i] >= k && a[i+1] >= k;
}
bool check(int x) {
	for (int i = 0;i < n-1; i++) {
		if (sm(n-i-1, x) || sm(n+i, x)) return false;
		if (bi(n-i-1, x) || bi(n+i, x)) return true;
	}
	return a[1] >= x;
}
int main() {
	read(n);
	for (int i = 1;i <= 2*n-1; i++) read(a[i]);
	int l = 1, r = 2 * n-1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) l = mid + 1;
		else r = mid - 1;
	}
	cout << r << endl;
	return 0;
}
