#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
//int INF = numeric_limits<int>::max();

int main(int, char**) {
	string x; cin >> x;
	int rem = 0;
	int cnt = 0;
	for (int i=0; i<x.size(); i++) {
		char c = x[i];
		if (c=='S') {
			cnt++;
		} else if (cnt>0) {
			rem++;
			cnt--; 
		}
	}
	cout << x.size() - 2*rem << endl;
	return 0;
}