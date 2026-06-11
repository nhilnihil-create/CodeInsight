#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

const int64 mod = 1000000007;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	int64 answer = 1;
	int remaining = 0;
	int last = 1;

	for (int i = 0; i < n; ++i){
		int x; cin >> x;

		if (x >= last){
			remaining++;
			last += 2;
		}
		else if (x + 1 == last){
			answer = answer * (remaining + 1) % mod;
		}
	}

	while (remaining)
		answer = answer * remaining-- % mod;

	cout << answer << endl;

	return 0;
}