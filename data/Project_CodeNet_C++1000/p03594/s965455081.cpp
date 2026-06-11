#include<bits/stdc++.h>
using namespace std;
#define MAXN 1005

int N, M, D;
int d[MAXN];
char m[] = { 'R', 'Y', 'G', 'B' };

int main(){
	scanf( "%d%d%d", &N, &M, &D );
	for ( int i = D, I(max( N << 1, M << 1 )); i <= I; ++i ) d[i] = d[i - D] + 1;
	for ( int i = 1; i <= N; ++i, putchar('\n') )
		for ( int j = 1; j <= M; ++j )
			putchar( m[( d[i + j] & 1 ) << 1 | ( d[i - j + M] & 1 )] );
	return 0;
}