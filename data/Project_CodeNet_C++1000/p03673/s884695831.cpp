#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
#include <bitset>
#include <cmath>
#include <stack>
#include <iomanip>
#include <map>
#include <math.h>
#include <list>
#include <deque>
typedef long long ll;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int MOD = 1000000007;
const ll INF = 1LL << 60;

ll GCD(ll a, ll b) { return b ? GCD(b, a%b) : a; }
ll LCM(ll a, ll b) {return a / GCD(a, b) * b;}

int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	deque<int> b;
	for(int i = 0; i < n; i++)
	{
		if(i % 2 == 0) b.push_back(a[i]);
		if(i % 2 != 0) b.push_front(a[i]);
	}
	if(n % 2 == 0)
	{
		for(int i = 0; i < n - 1; i++)
		{
			cout << b[i] << " ";
		}
		cout << b[n - 1] << endl;
	}
	else
	{
		for(int i = n - 1; i >= 1; i--)
		{
			cout << b[i] << " ";
		}
		cout << b[0] << endl;
	}
}