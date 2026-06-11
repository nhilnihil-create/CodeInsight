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
ll a, b;
int main()
{
	cin >> a >> b;
	if (a == 0 || b == 0)cout << "Zero" << endl;
	else if (a > 0)cout << "Positive" << endl;
	else if (b < 0) {
		int x = b - a + 1;
		if (x % 2)cout << "Negative" << endl;
		else cout << "Positive" << endl;
	}
	else cout << "Zero" << endl;
	return 0;
}