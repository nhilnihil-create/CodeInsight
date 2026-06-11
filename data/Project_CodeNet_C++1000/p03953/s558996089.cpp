#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int n, m;
ll k, e[maxn];
int x[maxn], a[maxn];
int b[maxn], c[maxn], d[maxn];

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &x[i]), b[i] = d[i] = i;
	scanf("%d%lld", &m, &k);
	for(int i = 1;i <= m;i++) scanf("%d", &a[i]), swap(b[a[i]], b[a[i] + 1]);
	while(k){
		if(k & 1){
			for(int i = 1;i <= n;i++) c[i] = d[b[i]];
			for(int i = 1;i <= n;i++) d[i] = c[i];
		}
		for(int i = 1;i <= n;i++) c[i] = b[b[i]];
		for(int i = 1;i <= n;i++) b[i] = c[i];
		k >>= 1;
	}
	for(int i = 1;i <= n;i++) printf("%lld\n", e[i] = e[i - 1] + x[d[i]] - x[d[i] - 1]);
}