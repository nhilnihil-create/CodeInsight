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



int main()

{
	int N;

	cin >> N;
	vector<int> t(N);
	vector<int> a(N);

	for (int i = 0; i < N; i++)
	{
		cin >> t[i] >> a[i];
	}

	ll ta = t[0];
	ll aa = a[0];

	for (int i = 1; i < N; i++)
	{
		ll ti = t[i];
		ll ai = a[i];
		ll n = max((ta + ti - 1) / ti, (aa + ai - 1) / ai);
		ta = n * ti;
		aa = n * ai;

	}

	cout << ta + aa << endl;
	
	return 0;
	
}