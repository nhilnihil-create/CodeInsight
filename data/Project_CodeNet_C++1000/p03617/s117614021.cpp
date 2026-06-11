#include <bits/stdc++.h>

using namespace std;

int main() {

	int q, h, s, d;
	cin >> q >> h >> s >> d;
	long long n;
	cin >> n;
	n *= 8;

	vector<pair<int, int>> tanka(4);

	tanka[0] = make_pair( q * 8,2);
	tanka[1] = make_pair( h * 4,4);
	tanka[2] = make_pair( s * 2,8);
	tanka[3] = make_pair( d * 1,16);

	sort(tanka.begin(), tanka.end());

	long long res=0;

	for (int i = 0; i < 4; i++) {
		res += n / tanka[i].second*tanka[i].first/(16/tanka[i].second);
		n = n % tanka[i].second;
	}

	cout << res << endl;

	return 0;
}