#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
	deque<int>dq;
	int n,cnt=1,b=0;
	cin >> n;
	vector<int>arr(n);
	rep(i, n)cin >> arr[i];
	if (n % 2 == 0)b = 1;
	rep(i, n) {
		if (i % 2 == b)dq.push_front(arr[i]);
		else dq.push_back(arr[i]);
	}
	for (auto d : dq) {
		if (cnt == n)cout << d << endl;
		else cout << d << " ";
		cnt++;
	}

	return 0;
}

