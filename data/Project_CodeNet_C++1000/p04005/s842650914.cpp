#include<iostream>
using namespace std;
#include<algorithm>
#include<cstring>
#include<string>
#include<stdio.h>
#include<map>
#include<vector>
#include<cmath>
#include<iomanip>
#include<queue>
#include<stack>
#include<set>
#define maxn 1000005
#define INF 1e9
#define ll long long
ll a[3],dif;
int main()
{
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a + 3);
	dif = a[0] * a[1];
	if (a[2] % 2)cout << dif << endl;
	else cout << "0" << endl;
	return 0;
}