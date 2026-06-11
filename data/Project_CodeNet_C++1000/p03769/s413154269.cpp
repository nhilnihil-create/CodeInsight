#include <bits/stdc++.h>

#define debug(x) cout << #x << " = " << x << endl
#define fori(i, ini, lim) for(int i = int(ini); i < int(lim); i++)
#define ford(i, ini, lim) for(int i = int(ini); i >= int(lim); i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

// returns a permutation pK of K elements such that if 
// it has a increasing sequence of K elements concataned
// after it, the total of good subsequences will be 'size',
// considering that an empty subsequence is a good one.
vector<int> roll(ll size) {
	if(size == 1) {
		return vector<int>();
	}
	vector<int> v;
	if(size & 1) {
		v = roll(size - 1);
		v.insert(v.begin(), v.size() + 1);
	}
	else {
		v = roll(size / 2);
		v.push_back(v.size() + 1);
	}
	return v;
}

int main() {
	ios_base::sync_with_stdio(false);

	ll n;
	cin >> n;
	
	vector<int> p = roll(n + 1);
	int total = p.size();
	fori(i, 1, total + 1) {
		p.push_back(i);
	}

	cout << p.size() << '\n';
	for(auto &each : p) {
		cout << each << " ";
	}
	cout << '\n';

	return 0;
}

