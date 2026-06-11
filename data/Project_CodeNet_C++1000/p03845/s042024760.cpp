#include <iostream>
#include <stack>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

#define rep(i,n) for(int i=0; i < n; i++)
using ll =  long long;
using namespace std;
#define pi 3.14159265358979

int main()
{
	int n, total = 0;
	cin >> n;
	vector<int> time(n);
	rep(i, n)
	{
		cin >> time[i];
		total += time[i];
	}

	int m;
	cin >> m;
	rep(i, m)
	{
		int p, x;
		cin >> p >> x;

		cout << total - time[p-1] + x;
		if (i < m - 1) cout << endl;
	}
	return 0;
}