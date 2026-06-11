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
	int N,M;
	cin >> N;
	vector<int> s(N);
	int sum = 0;
	for(int i = 0; i < N; i++) cin >> s[i],sum += s[i];
	if(sum % 10 != 0)
	{
		cout << sum << endl;
		return 0;
	}
	sort(s.begin(),s.end());
	int max = sum;
	for(int i = 0; i < N; i++)
	{
		max -= s[i];
		if(max % 10 != 0)
		{
			cout << max << endl;
			return 0;
		}
		max += s[i];
	}
	cout << 0 << endl;
}
