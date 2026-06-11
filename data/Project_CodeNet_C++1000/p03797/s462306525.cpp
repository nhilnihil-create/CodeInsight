#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <iomanip>
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define rrep(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
ll mod = 1e9 + 7;

using namespace std;
using Graph = vector<vector<int>>;
Graph G;


int main()
{
	ll S, M;
	cin >> S >> M;
	if (2 * S > M)
	{
		cout << M / 2 << endl;
	}
	else
	{
		cout << S + (M - 2 * S) / 4 << endl;
	}
	
	return 0;
}
