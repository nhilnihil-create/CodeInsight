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
	cin >> N >> M;
	vector<pair<int,int> > a(M);
	vector<bool> reach(N,false);
	for(int i = 0; i < M; i++)
	{
		cin >> a[i].first >> a[i].second;
		if(a[i].second == N) reach[a[i].first] = true;
	}
	sort(a.begin(),a.end());
	bool ok = false;
	int A = 0;
	for(int i = 0; i < M; i++)
	{
		if(a[i].first == 1)
		{
			if(reach[a[i].second]) ok = true;
		}
	}
	if(ok) cout << "POSSIBLE" << endl;
	else cout << "IMPOSSIBLE" << endl;
}
