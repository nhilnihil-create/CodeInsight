#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
inline char nc() {
	return getchar();
	static char buf[100000], *l = buf, *r = buf;
	return l==r&&(r=(l=buf)+fread(buf,1,100000,stdin),l==r)?EOF:*l++;
}
template<class T> void read(T &x) {
	x = 0; int f = 1, ch = nc();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=nc();}
	while(ch>='0'&&ch<='9'){x=x*10-'0'+ch;ch=nc();}
	x *= f; 
}
const int maxn = 1e5 + 50;
int n;
int a[maxn];
inline int cmp(const int &a, const int &b) {
	return a > b;
}
bool solve() {
	sort(a + 1, a + n + 1, cmp);
	int k = 1;
	while(a[k + 1] >= k + 1) ++k;
	int x = a[k] - k;
	int y = 0;
	while(a[k + y + 1] == k) ++y;
	return (x & 1) || (y & 1);
}
int main() {
	read(n);
	for(int i = 1; i <= n; ++i) {
		read(a[i]);
	}
	puts(solve() ? "First" : "Second");
	return 0;
}