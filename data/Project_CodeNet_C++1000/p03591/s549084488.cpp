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

int main()
{
	cin >> s;
	if (s.substr(0, 4) == "YAKI")
		cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}
