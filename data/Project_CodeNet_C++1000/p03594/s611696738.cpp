#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

#define For(i, j, k) for(int i = j; i <= k; i++)
#define Forr(i, j, k) for(int i = j; i >= k; i--)

using namespace std;

const int N = 510;

const char S[5] = "RYGB";
char col[N][N];
int d, n, m;

int main(){
	scanf("%d%d%d", &n, &m, &d);
	For(i, 1, n) For(j, 1, m)
		col[i][j] = S[(((i + j) / d) & 1) << 1 | (((i - j + m) / d) & 1)];
	For(i, 1, n) printf("%s\n", col[i] + 1);
	return 0;
}