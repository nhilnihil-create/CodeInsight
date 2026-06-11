#include <bits/stdc++.h>

using namespace std;

#define ll long long

//#define TEST

struct Grid {
private:
	int h, w;
	ll* count; // 3*3のうち、i個塗られたものが何個あるか、を格納
	int dx[3]{ 0,1,2 };
	int dy[3]{ 0,1,2 };
	set<pair<int, int>> b; // 塗りつぶしたマス
	/* 上からy,左からx、を左上に持つ3*3中の黒マス */
	int count_b(int y, int x) {
		if (y > h - 2) return -1;
		if (x > w - 2) return -1;
		if (x <= 0) return -1;
		if (y <= 0) return -1;
		vector<pair<int, int>> sq;
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				sq.push_back(make_pair(y + dy[i], x + dx[j]));
		int c = 0;
		for (auto sqi : sq) {
			auto iter = b.find(sqi);
			if (iter != b.end())
				++c;
		}
		return c;
	}
	/* 上からy,左からxを塗る */
	void paint(int y, int x) {
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				int c = count_b(y - dy[i], x - dx[j]);
				if (c == -1) continue;
				--count[c];
				++count[c + 1];
			}
		}
		b.insert(make_pair(y, x));
#ifdef TEST
		cout << "----------paint " << y << " " << x << "----------" << endl;
		show();
#endif
	}
	/* countを表示する */
	void show() {
		for (int i = 0; i < 10; ++i)
			cout << count[i] << " ";
		cout << endl;
	}
public:
	Grid(int h, int w) {
		count = new ll[10];
		for (int i = 1; i < 10; ++i)
			count[i] = 0;
		this->h = h;
		this->w = w;
		count[0] = (ll)(h - 2) * (w - 2);
#ifdef TEST
		cout << "----------first----------" << endl;
		show();
#endif
	}
	void solve(vector<pair<int, int>> ab) {
#ifdef TEST
		cout << "----------ans-----------" << endl;
#endif
		for (auto abi : ab)
			paint(abi.first, abi.second);
		for (int i = 0; i < 10; ++i)
			cout << count[i] << endl;
		delete[] count;
	}
};

signed main() {
	int h, w, n;
	cin >> h >> w >> n;

	Grid g(h, w);

	vector<pair<int, int>> ab;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		ab.push_back(make_pair(a, b));
	}

	g.solve(ab);

	return 0;
}