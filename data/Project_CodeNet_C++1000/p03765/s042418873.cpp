
#include<iostream>
#include<cstdio>
#include<cstring>
#include <cstdlib>  
#include <math.h>
#include <cmath>
#include<cctype>
#include<string>
#include<set>
#include<iomanip>
#include <map>
#include<algorithm>
#include <functional>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include<bitset>
#include <deque>
#include <climits>
#include <typeinfo>
#include <utility> 
using namespace std;
using ll = long long;
template<typename T>using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
const ll inf = 1LL << 60;
#define all(x) (x).begin(),(x).end()
#define puts(x) cout << x << endl
#define rep(i,m,n) for(ll i = m;i < n;++i)
#define pb push_back
#define fore(i,a) for(auto &i:a)
#define rrep(i,m,n) for(ll i = m;i >= n;--i)
#define INF INT_MAX/2

int ssum[2][101010], tsum[2][101010];
int main() {
	string s, t;
	cin >> s >> t;
	rep(i, 0, s.size()) {
		ssum[s[i] - 'A'][i + 1] += ssum[s[i] - 'A'][i] + 1;
		ssum[!(s[i] - 'A')][i + 1] = ssum[!(s[i] - 'A')][i];
	}
	rep(i, 0, t.size()) {
		tsum[t[i] - 'A'][i + 1] += tsum[t[i] - 'A'][i] + 1;
		tsum[!(t[i] - 'A')][i + 1] = tsum[!(t[i] - 'A')][i];
	}
	int q;
	cin >> q;
	rep(i, 0, q) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a--, b--, c--, d--;
		string s1, s2;
		int diff1 = (ssum[1][b + 1] - ssum[1][a]) - (ssum[0][b + 1] - ssum[0][a]);
		if(diff1 > 0) {
			if (diff1 % 3 == 0)s1 = "";
			else if (diff1 % 3 == 1)s1 = "B";
			else s1 = "A";
		}
		else if (diff1 == 0) {
			s1 = "";
		}
		else {
			if (-diff1 % 3 == 0)s1 = "";
			else if (-diff1 % 3 == 1)s1 = "A";
			else s1 = "B";
		}
		int diff2 = (tsum[1][d + 1] - tsum[1][c]) - (tsum[0][d + 1] - tsum[0][c]);
		if (diff2 > 0) {
			if (diff2 % 3 == 0)s2 = "";
			else if (diff2 % 3 == 1)s2 = "B";
			else s2 = "A";
		}
		else if (diff2 == 0) {
			s2 = "";
		}
		else {
			if (-diff2 % 3 == 0)s2 = "";
			else if (-diff2 % 3 == 1)s2 = "A";
			else s2 = "B";
		}
		if (s1 == s2)puts("YES");
		else puts("NO");
	}
	return 0;
}
