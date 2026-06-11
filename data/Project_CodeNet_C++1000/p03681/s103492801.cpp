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

ll facctorialMethod(ll k){
    ll sum = 1;
    for (int i = 1; i <= k; ++i)
    {
        sum *= i;
		sum %= MOD;
    }
    return sum;
}

int main()
{
	int N,M;
	cin >> N >> M;
	if(abs(N - M) > 1)
	{
		cout << 0 << endl;
		return(0);
	}
	ll a,b;
	a = facctorialMethod(N);
	b = facctorialMethod(M);
	ll ans = a * b % MOD;
	if(N == M) ans = ans * 2 % MOD;
	cout << ans << endl;
}
