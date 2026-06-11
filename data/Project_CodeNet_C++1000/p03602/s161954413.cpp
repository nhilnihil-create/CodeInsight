#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <string.h>
#include <cmath>

using namespace std;
typedef long long i64;
typedef long double ld;
typedef pair<i64,i64> P;
#define rep(i,s,e) for(int (i) = (s);(i) <= (e);++(i))

int n;

i64 a[310][310];

bool f[310][310];

int main()
{
	cin >> n;
	rep(i,1,n) rep(j,1,n)
		cin >> a[i][j];
	
	rep(k,1,n) rep(i,1,n) rep(j,1,n)
	{
		if(i == j || i == k || j == k) continue;
		if(a[i][j] > a[i][k] + a[k][j])
		{
			cout << -1 << endl;
			return 0;
		}
		if(a[i][j] == a[i][k] + a[k][j])
		{
			f[i][j] = 1;
		}
	}
	i64 result = 0;

	rep(i,1,n) rep(j,1,i)
	{
		if(!f[i][j]) result += a[i][j];
	}
	cout << result << endl;
	return 0;
}
	

