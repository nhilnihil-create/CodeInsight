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
#define sz(x) (int)(x).size()
#define Cout(s) cout<<s<<endl
using namespace std;
typedef long long ll;
string Yes(bool b) { if (b) { return "Yes"; } else { return "No"; } }
string YES(bool b) { if (b) { return "YES"; } else { return "NO"; } }
//================================================
int ketawa(int a) {
	if (a < 10)return a;
	else return a % 10 + ketawa(a / 10);
}

int a = 1, b = 0, c, d, n, k = 0, ans = 0;
string s, t;
int mod = 1000000007;

int main()
{
	int n; cin >> n;
	vector<int> a(n); rep(i, n) { cin >> b; a[i] = b - 1; }
	int cnt = 0;
	rep(i, n) {
		if (a[a[i]] == i)cnt++;
	}
	cout << cnt / 2 << endl;

	return 0;
}
