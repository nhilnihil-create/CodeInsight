#include <iostream>
#include <vector>
#include <math.h>
#include <map>
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <functional>
#include <string>
using namespace std;
#define MP make_pair
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
typedef pair<int, int> P;
typedef pair<pair<P, P>, P>PP;
typedef long long LL;
#define INF LL(1e18)
#define N 1000000000
LL ans, temp;
int search(LL s, LL e, LL i)
{
	char a;
	LL mid = (s + e) / 2;
	cout << "? " << ans + mid * i << endl;
	cin >> a;
	if(mid - s == 1 && a == 'Y')
	{
		return s;
	}
	if(e - mid == 1 && a == 'N')
	{
		return mid;
	}
	return a == 'Y' ? search(s, mid, i): search(mid, e, i);
}
int solve(LL s, LL e, LL i)
{
	char a;
	if(s){
		cout << "? " << s * i + ans << endl;
		cin >> a;
		if(a == 'Y')
	 	 return s; 
	}
	cout << "? " << e * i + ans << endl;
	cin >> a;
	if(a == 'N')
	 return e;
	return search(s, e, i);
}
int main()
{

	for(LL i = LL(1e10); i > 1; i /= 10)
	{
		if(i == LL(1e10))
			ans += solve(1, 9, i) * i;
		else
			ans += solve(0, 9, i) * i;
	}
	char a;
	cout << "? " << ans << endl;
	cin >> a;
	ans /= 10;
	if(a == 'N')
	{
		ans++;
	}
	
	while(!(ans % 10))
	{	
		ans /= 10;
		if(ans % 10 != 9)
		{
			cout << "? " <<  ans + 1 << endl;
			cin >> a;
			if(a == 'N')
			{
				ans *=10;
				break;
			}
		}
		else
		{
			cout << "? " <<  ans - 1 << endl;
			cin >> a;
			if(a == 'Y')
			{
				break;
			}
		}
	}
	cout << "! " << ans << endl;
	return 0;
}