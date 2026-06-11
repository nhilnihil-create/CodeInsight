#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
 
#define For(i, j, k) for(int i = j; i <= k; i++)
 
const int N = 100010;
 
double A[N];
int n, m, pos[N], op[N], C[N], P[N], tmp[N];
long long k;
 
void mul(int *u, int *v){
	For(i, 1, n - 1) tmp[i] = v[u[i]];
	For(i, 1, n - 1) u[i] = tmp[i];
}
 
int main(){
	scanf("%d", &n);
	For(i, 1, n) scanf("%lf", &A[i]), pos[i] = C[i] = i;
	scanf("%d%lld", &m, &k);
	For(i, 1, m) scanf("%d", &op[i]), std::swap(pos[op[i]], pos[op[i] - 1]);
	For(i, 1, n - 1) P[pos[i]] = i;
 
	while(k){
		if(k & 1) mul(C, P);
		mul(P, P);
		k >>= 1;
	}
 
	For(i, 1, n - 1) pos[C[i]] = i;
 
	double now = A[1];
	printf("%.0lf\n", now);
	For(i, 1, n - 1) printf("%.0lf\n", now += A[pos[i] + 1] - A[pos[i]]);
 
	return 0;
}