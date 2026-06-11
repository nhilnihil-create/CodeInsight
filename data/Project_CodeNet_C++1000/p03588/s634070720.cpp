#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <list>
#include <numeric>
#include <map>
#include <cmath>
#include <string>

#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define Cout(s) cout<<s<<endl
typedef long long ll;
using namespace std;
string Yes(bool b) { if (b) { return "Yes"; } else { return "No"; } }
string YES(bool b) { if (b) { return "YES"; } else { return "NO"; } }
//================================================

ll a = 0, b = 0, c, d, n, k = 0;
string s, t;



int main()
{
	ll a=0, n;
	cin >> n; ll cnt = 0, ans = 0;
	for(ll i=0;i<n;i++)
	{
		cin >> a >>b;
		if (cnt < a)
		{
			cnt = a; ans = b;
		}
	}

	cout << ans+cnt << endl;

	return 0;
}