#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>

using namespace std;

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define REPO(i, n) for(int i = 1;i <= n;i++)
#define ll long long
#define INF 1999999999
#define MINF -1999999999
#define INF64 1999999999999999999
#define ALL(n) n.begin(),n.end()
#define ABS(a,b) max(a,b) - min(a,b)


int main() {
	ll n,s = 0,wo,ss;
	cin >> n;
	REPO(i, INF) {
		if (s >= n) {
			ss = i - 1;
			break;
		}
		s += i;
	}
	wo = s - n;
	REPO(i, ss) {
		if (i != wo) {
			cout << i << endl;
		}
	}
}