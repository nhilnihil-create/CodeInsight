#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, t;
int x, mx, mn, cnt;

int main(){
	scanf("%d%d", &n, &t);
	mn = 1e9;
	for(int i = 1;i <= n;i++){
		scanf("%d", &x);
		if(x - mn > mx){
			mx = x - mn, cnt = 1;
		}else if(x - mn == mx) cnt++;
		mn = min(mn, x);
	}
	printf("%d", cnt);
}