#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;

const int MAXN = 1e5 + 10;
int N;
int A[MAXN];
int p, t;

int main() {
	register int i;
	scanf( "%d", &N );
	for( i = 1; i <= N; ++i )
		scanf( "%d", A + i );
	sort( A + 1, A + N + 1 );
	while(A[N - p] >= p + 1) ++p;
	while(A[N - p - t + 1] >= p ) ++t;
	puts( (A[N - p + 1] - p + 1) & 1 && t & 1 ? "Second" : "First" );
	return 0;
}