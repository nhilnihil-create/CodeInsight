#include "bits/stdc++.h"

#define REP(i,n) for(int i=0;i< (n);i++)
#define REPR(i, n) for(int i = (n);i >= 0;i--)
#define FOR(i, m, n) for(int i = (m);i < (n);i++)
#define FORR(i, m, n) for(int i = (m);i >= (n);i--)
#define SORT(v, n) std::sort(v, v+n);
#define VSORT(v) std::sort(v.begin(), v.end());
#define VRSORT(v) std::sort(v.rbegin(), v.rend());
#define ll long long
#define pb(a) push_back(a)
#define ALL(obj) (obj).begin(),(obj).end()

using namespace std;

const int INF = 99999999;
const ll LINF = 9999999999999;

typedef pair<ll, ll> LP;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


string S;

ll dfs(ll index,ll times,ll num) {
	ll add = (S[index] - '0') * times;
	if (index + 1 == S.size()) {return num + add; }
	return dfs(index + 1, times * 10,num+ add) + dfs(index + 1, 1, num + add);
}

int main() {
	cin >> S;
	reverse(ALL(S));

	cout << dfs(0, 1,0)<<endl;

	return 0;
}