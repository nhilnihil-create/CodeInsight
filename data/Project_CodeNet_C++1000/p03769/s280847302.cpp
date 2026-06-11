#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()
#define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 200000 + 10;
const int MOD = 1000000007;
const int LOG = 20;
const int INF = 1000000010;
const int delta = 11353;

int n;
deque<int> dq;

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	n++;
	int last = 0;
	for (int i = 0; i < 60; i++){
		if (n & (1ll << i)) last = i;
	}
	int pnt = 0;
	for (int i = last - 1; i >= 0; i--){
		//cout << pnt << '\n';
		dq.push_front(++pnt);
		if (n & (1ll << i)) dq.push_back(++pnt);
		//cout << dq.back() << ' ' << dq.front() << '\n';
	}
	vi ans;
	while (dq.size()) ans.pb(dq.back()), dq.pop_back();
	for (int i = 1; i <= pnt; i++) ans.pb(i);
	cout << ans.size() << '\n';
	for (auto u:ans)cout << u << ' ';

	return 0;
}
