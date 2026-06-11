//番号を保って向きを変える、は、すれちがって番号を変えると解釈できる。
//そうすると、1回ぶつがるごとに蟻の番号は+1, または, -1変化する。これは蟻の進む向きによる。
//各蟻についてぶつかる回数を求めるのが本質で、これは適当にO(1)でできる。
//最後にぶつかったまま止まる場合が厄介。最後はぶつかったとみなす。
#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
#define rep(i, n) for (i = 0; i < n; i++)
using namespace std;
typedef pair<int, int> P;

int n, L, t;
int x[100000], w[100000];
vector<P> rights;	//(pos, id)
vector<P> lefts;
int ans[100000];

signed main() {
	int i;
	
	cin >> n >> L >> t;
	
	rep(i, n) {
		cin >> x[i] >> w[i];
		if (w[i] == 1) rights.push_back(P(x[i], i));
		else lefts.push_back(P(x[i], i));
	}
	sort(rights.begin(), rights.end());
	sort(lefts.begin(), lefts.end());
	
	int rsz = rights.size(); rep(i, rsz) rights.push_back(P(rights[i].first + L, rights[i].second));
	int lsz = lefts.size(); rep(i, lsz) lefts.push_back(P(lefts[i].first + L, lefts[i].second));
	//cout << endl;
	//rep(i, rights.size()) cout << rights[i].first << " " << rights[i].second << endl; cout << endl;
	//rep(i, lefts.size()) cout << lefts[i].first << " " << lefts[i].second << endl; cout << endl;
	
	rep(i, rsz) {
		int l = upper_bound(lefts.begin(), lefts.end(), P(rights[i].first, 114514)) - lefts.begin();
		int r = upper_bound(lefts.begin(), lefts.end(), P(rights[i].first + (2 * t) % L, 114514)) - lefts.begin();
		int cnt = r - l + lsz * ((2 * t) / L);
		int id = (rights[i].second + cnt % n) % n;
		int pos = (rights[i].first + t % L) % L;
		ans[id] = pos; //cout << id << endl;
	}
	
	rep(i, lsz) {
		int l = upper_bound(rights.begin(), rights.end(), P(lefts[i + lsz].first - (2 * t) % L, -114514)) - rights.begin();
		int r = upper_bound(rights.begin(), rights.end(), P(lefts[i + lsz].first, -114514)) - rights.begin();
		int cnt = r - l + rsz * ((2 * t) / L);
		int id = (lefts[i + lsz].second - cnt % n + n) % n;
		int pos = (lefts[i + lsz].first - t % L) % L;
		ans[id] = pos; //cout << id << endl;
	}
	
	rep(i, n) {
		cout << ans[i] << endl;
	}
	return 0;
}