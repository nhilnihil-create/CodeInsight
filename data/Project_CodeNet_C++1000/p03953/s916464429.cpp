#include <bits/stdc++.h>
#define MAX 100005
#define ll long long
#define P 998244353
using namespace std;

int n, m;
ll k, b[MAX];
double a[MAX], tmp[MAX];

void calc(ll k){
	while(k){
		if(k&1){
			for(int i = 1; i <= n; i++) tmp[i] = a[b[i]];
			for(int i = 1; i <= n; i++) a[i] = tmp[i];
		}
		for(int i = 1; i <= n; i++) tmp[i] = b[b[i]];
		for(int i = 1; i <= n; i++) b[i] = tmp[i];
		k >>= 1;
	}
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++){
		scanf("%lf", &a[i]);
		b[i] = i;
	}
	for(int i = n; i >= 1; i--){
		a[i] -= a[i-1];
	}
	cin >> m >> k;
	int x;
	for(int i = 1; i <= m; i++){
		scanf("%d", &x);
		swap(b[x], b[x+1]);
	}
	calc(k);
	double s = 0;
	for(int i = 1; i <= n; i++){
		s += a[i];
		printf("%.1lf\n", s);
	}
	
	return 0;
}