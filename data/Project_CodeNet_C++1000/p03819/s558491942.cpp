#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const int MAXN = 100005;
const int mod = 1e9 + 7;

int n, m, a[MAXN];
int b[MAXN];

int main(){
	scanf("%d %d",&n,&m);
	while(n--){
		int l, r; scanf("%d %d",&l,&r);
		l--;
		for(int i=1; i<=505; i++){
			if(r / i != l / i) a[i]++;
		}
		if(506 <= r){
			b[506]++;
			b[r+1]--;
			for(int i=1; i<=200; i++){
				// xi <= l < x(i+1)
				// xi <= r < x(i+1)
				int ed = l / i;
				int st = (r + i + 1) / (i + 1);
				st = max(st, 506);
				if(st <= ed){
					b[st]--;
					b[ed+1]++;
				}
			}
		}
	}
	for(int i=1; i<=m; i++) b[i] += b[i-1];
	for(int i=1; i<=m; i++) printf("%d\n", a[i] + b[i]);
}
