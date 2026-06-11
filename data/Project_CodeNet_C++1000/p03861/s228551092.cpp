#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define lld long long int
#define ld long double
#define mpi 3.14159265358979323846
#define mod 1000000007
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lld a,b,x;
	cin >> a >> b >> x;
	lld y = a%x;
	if(y==0)
	{
		//do nothing;
	}
	else
	{
		a = a-y;
		a+=x;
	}
	y = b%x;
	b = b-y;
	cout << ((b-a)/x)+1 << "\n";
	return 0;
}
