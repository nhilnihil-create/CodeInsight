#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int n;
int a[maxn], b[maxn];

inline bool check(int x){
	for(int i = 1;i <= 2 * n - 1;i++) b[i] = a[i] >= x;
    x = 0;
	for(int i = 2;i <= 2 * n - 1;i++){
		if(b[i] == b[i - 1]){
			if(abs(i - n) < abs(x - n)) x = i;
			if(abs(i - 1 - n) < abs(x - n)) x = i - 1;
		}
	}
	if(!x) return b[n] ^ ((n - 1) & 1);
	return b[x];
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= 2 * n - 1;i++) scanf("%d", &a[i]);
	int l = 1, r = 2 * n - 1, mid;
	while(l < r){
		mid = (l + r >> 1) + 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	printf("%d", l);
}