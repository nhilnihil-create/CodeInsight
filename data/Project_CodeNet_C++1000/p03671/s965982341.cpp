#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
	int a, b,c;
	cin >> a >> b >> c;
	int ans = 0;
	if (a > b && a > c)
		ans = b + c;
	else if (b > a && b > c)
		ans = a + c;
	else
		ans = a + b;
	cout << ans << endl;

} 