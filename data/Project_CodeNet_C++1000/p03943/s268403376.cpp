#include <bits/stdc++.h>
using namespace std;
#define ll long long 


int main()
{
	ll t, n, m, i, j, k, a, b, c;

	scanf("%lld %lld %lld", &a, &b, &c);

	if(a>b) swap(a, b);
	if(b>c) swap(b, c);
	if(a>b) swap(a, b);

	if(a+b==c) printf("Yes\n");
	else printf("No\n");




	return 0;
}