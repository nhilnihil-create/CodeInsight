#include<iostream>
#include<climits>
#include<vector>
#include<list>
#include<functional>
#include<algorithm>
#include<string>
#include<cmath>
#include<complex>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<tuple>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll X;
	cin >> X;
	ll n = 0;
	ll sum = 0;
	while (sum < X) sum += ++n;
	cout << n << "\n";

	return 0;
}