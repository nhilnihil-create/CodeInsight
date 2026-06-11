#include<algorithm>
#include<cmath>
#include<climits>
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
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<bool> vb;
const ll MOD = 1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
#define repl(i,s,e) for(int i=s;i<e;i++)
#define reple(i,s,e) for(int i=s;i<=e;i++)
#define revrep(i,n) for(int i=n-1;i>=0;i--)
#define all(x) (x).begin(),(x).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main()
{
	int N;
	cin >> N;

	vll A(N);
	rep(i, N) cin >> A[i];

	sort(all(A));

	vll S(N);
	ll s = 0;
	rep(i, N)
	{
		S[i] = 2 * s - A[i];
		s += A[i];
	}

	int count = 0;
	for(int i = N - 1;i >= 1;i--)
	{
		if (S[i] < 0)
		{
			count += i;
			break;
		}
	}

	cout << N - count << endl;

	return 0;
}