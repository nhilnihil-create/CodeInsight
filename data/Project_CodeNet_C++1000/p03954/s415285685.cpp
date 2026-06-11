#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 200200;
int n, a[N], tmp[N], ans; 
bool check(int x) {
	for(int i = 1; i <= 2 * n - 1; i++) tmp[i] = ( a[i] >= x );
	int l, r; l = r = n;
	for( ; l >= 1; l--, r++) {
		if(tmp[l] == tmp[l + 1]) return tmp[l];
		if(tmp[r] == tmp[r - 1]) return tmp[r];
	}
	return tmp[n] ^ (n & 1) ^ 1;
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= 2 * n - 1; i++) 
        scanf("%d", &a[i]);
    int l = 1, r = 2 * n;
    while(l <= r) {
    	int mid = (l + r) / 2;
    	if(check(mid)) l = mid + 1, ans = mid;
    	else r = mid - 1;
	}
	printf("%d\n", ans);
	return 0;
}