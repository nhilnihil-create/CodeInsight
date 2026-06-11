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
	int n, m;
	cin >> n >> m;
	vector<int> city(n);
	rep(i, m)
	{
		int in, out;
		cin >> in >> out;
		city[in - 1] ++;
		city[out - 1] ++;
	}
	rep(i, n) cout << city[i] << endl;
	return 0;
}