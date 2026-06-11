#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int cnt = 3;
	if (a == b && b == c)
		cnt = 1;
	else if (a == b || b == c || c == a)
		cnt = 2;
	else
		cnt = 3;
	cout << cnt << endl;
} 