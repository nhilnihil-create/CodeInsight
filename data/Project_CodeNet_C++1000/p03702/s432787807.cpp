#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

const int MAXN = 100010;

int n;

lli A, B;

lli v[MAXN];

bool test(lli k)
{
	lli qtd = 0;

	for(int i = 1 ; i <= n ; i++)
	{
		if( v[i] <= B*k ) continue;

		lli remain = v[i] - B*k;

		qtd += remain/A;
		if( remain%A != 0 ) qtd++;
	}

	return ( qtd <= k );
}

int bs()
{
	int l = 0;
	int r = 1000000010;

	while( l < r )
	{
		int m = ( l + r )/2;

		if( test( m ) ) r = m;
		else l = m + 1;
	}

	return r;
}

int main()
{
	scanf("%d %lld %lld",&n,&A,&B);

	A -= B;

	for(int i = 1 ; i <= n ; i++)
		scanf("%lld",&v[i]);

	printf("%d\n",bs());
}