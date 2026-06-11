#include<algorithm>
#include<cmath>
#include<cstdio>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<string>
#include<utility>
#include<vector>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
#define repl(i,s,e) for(int i=s;i<e;i++)
#define reple(i,s,e) for(int i=s;i<=e;i++)
#define revrep(i,n) for(int i=n-1;i>=0;i--)
#define all(x) (x).begin(),(x).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }



ll gcd(ll a, ll b)
{
	if (a < b) {
		a ^= b;
		b ^= a;
		a ^= b;
	}

	return b ? gcd(b, a % b) : a;
}

int main()
{	
	int N, K;
	cin >> N >> K;

	set<ll> s;

	rep(i, N)
	{
		ll tmp;
		cin >> tmp;
		s.insert(tmp);
	}


	if (K > * s.rbegin())
	{
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}


	ll d = *s.begin();

	for (auto x : s)
	{
		d = gcd(d, x);
	}

	if (K % d == 0)
	{
		cout << "POSSIBLE" << endl;
	}
	else
	{
		cout << "IMPOSSIBLE" << endl;
	}

	return 0;
}