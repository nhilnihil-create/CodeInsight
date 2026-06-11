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
ll MOD = 1000000007;
ll INF = 1LL << 60;

ll GCD(ll a, ll b) { return b ? GCD(b, a%b) : a; }
ll LCM(ll a, ll b) {return a / GCD(a, b) * b;}

int main()
{
	ll N,x;
	cin >> N >> x;
	ll a[N];
	for(int i = 0; i < N; i++) cin >> a[i];
	ll count = 0;
	for(int i = 0; i < N -1; i++)
	{
		ll sum = a[i] + a[i + 1];
		if(sum > x)
		{
			ll diff = sum - x;
			if(diff <= a[i + 1]) count += diff,a[i + 1] -= diff;
			else
			{
				a[i + 1] = 0; count += diff;
			}
		}
	}
	cout << count << endl;
}
