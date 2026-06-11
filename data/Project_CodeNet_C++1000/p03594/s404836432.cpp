#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, x, n) for(int i = x; i < (int)n; ++i)

char an[500][501];

inline char id(int x){
	if (x == 0)return 'R';
	if (x == 1)return 'G';
	if (x == 2)return 'B';
	return 'Y';
}

int main(){
	int n, m, d;
	scanf("%d%d%d", &n, &m, &d);
	int c = 0;
	f(z, -(m - 1), n){
		if (z % d == 0)c ^= 2;
		f(i, 0, n){
			int j = i - z;
			if (j < 0 || j >= m)continue;
			int cc = c | ((i + j) / d & 1);
			an[i][j] = id(cc);
		}
	}
	f(i, 0, n)printf("%s\n", an[i]);
}