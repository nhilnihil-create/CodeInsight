#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n, x, cnt = 0;
int minv = 100005, maxv = -1;
int main(){
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &x);
        if (x == minv) cnt++;
        if (x < minv) minv = x, cnt=1;
        if (x > maxv) maxv = x;
    }
    if (maxv - minv > 1) {
    	puts("No");
    	return 0;
	}
    if (maxv == minv) {
        if (minv == n-1) {
        	puts("Yes");
        	return 0;
		}
        if (n / minv >= 2) puts("Yes");
		else puts("No");
		return 0;
    }
    int a = n - cnt, b = maxv - cnt;
    if (b < 1) puts("No");
    else if (a / b >= 2) puts("Yes");
    else puts("No");
    return 0;
}