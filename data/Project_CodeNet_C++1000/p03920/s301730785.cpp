#include "bits/stdc++.h"

#define debug(x) cout<<#x<<": "<<x<<endl
#define rep(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for (int i=(a);i<=(b);i++)
#define all(a) (a).begin(),(a).end()
using namespace std;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef long long ll;

set<int> mergeSet(set<int> s1, set<int> s2) {
	for (int ele : s2) {
		s1.insert(ele);
	}
	return s1;
}


void solve() {
#ifdef _WIN32
	istream &cin = ifstream("input.txt");
#endif

	int n;
	cin >> n;
	int i = 1, s = 0;
	while (s < n) {
		s += i;
		i++;
	}
	for (int j = 1; j < i; j++) {
		if (s - n != j) cout << j << endl;
	}
}




int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	solve();
#ifdef _WIN32
	system("PAUSE");
#endif
	return 0;
}