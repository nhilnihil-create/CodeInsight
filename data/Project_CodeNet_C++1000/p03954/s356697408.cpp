#include <cstdio>
#include <cctype>
#include <algorithm>
#define big(i, j) (a[i] >= x && a[j] >= x)
#define small(i, j) (a[i] < x && a[j] < x)
using namespace std;

int a[200005];
int n;

inline void in(register int &x){
	register char ch;
	x = 0;
	while(isspace(ch = getchar()));
	do x = x*10 + ch-'0'; while(isdigit(ch = getchar()));
}

bool check(int x){
	for(int i=1; i<n; i++){
		if(big(n-i, n-i+1) || big(n+i, n+i-1)) return true;
		if(small(n-i, n-i+1) || small(n+i, n+i-1)) return false;
	}
	return a[1] >= x;
}

int main(){
//	freopen("at2165.in", "r", stdin);
//	freopen("at2165.out", "w", stdout);
	in(n);
	for(int i=1; i<=n*2-1; i++)
		in(a[i]);
	int l = 1, r = n * 2 - 1, mid, ans;
	while(l <= r){
		mid = (l+r) >> 1;
		if(check(mid)){
//			printf("%d is valid.\n", mid);
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;//, printf("%d is invaild.\n", mid);
	}
	printf("%d\n", ans);
	return 0;
}
