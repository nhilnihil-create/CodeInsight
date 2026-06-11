#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
	char a, b, ans;
	cin >> a >> b;
	if (a == 'H')
		ans = b;
	else
	{
		if (b == 'H')
			ans = 'D';
		else
			ans = 'H';
	}
	cout << ans << endl;

} 