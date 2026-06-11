#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define st first
#define nd second
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
template <class T> T read(T &a) {
    a=0;char x=getchar();bool f=0;
    for(;x<'0'||x>'9';x=getchar())f|=x=='-';
	for(;x>='0'&&x<='9';x=getchar())a=(a<<3)+(a<<1)+x-'0';
    if(f)a=-a;
    return a;
}
using namespace std;


int d[500];

int main() {
	int ans = 0, n;
	read(n);
	n *= 2;
	for (int i = 1; i <= n; ++i) {
		read(d[i]);
	}
	sort(d + 1, d + n + 1);
	for (int i = 1; i <= n; i += 2) {
		ans += d[i];
	}
	cout << ans << endl;
	return 0;
}