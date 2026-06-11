#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(V) V.begin(),V.end()
const ll MOD = 1000000007;

int AC[100010], BC[100010];
int AT[100010], BT[100010];

int main() {
	string S, T;
	cin >> S;
	cin >> T;
	for (int i = 1;i <= S.size();i++) {
		if (S[i - 1] == 'A')AC[i] = 1, BC[i] = 0;
		else AC[i] = 0, BC[i] = 1;
	}
	for (int i = 1;i <= T.size();i++) {
		if (T[i - 1] == 'A')AT[i] = 1, BT[i] = 0;
		else AT[i] = 0, BT[i] = 1;
	}

	for (int i = 1;i <= S.size();i++) {
		AC[i] += AC[i - 1];
		BC[i] += BC[i - 1];
	}
	for (int i = 1;i <= T.size();i++) {
		AT[i] += AT[i - 1];
		BT[i] += BT[i - 1];
	}

	int Q, a, b, c, d, x, y;
	cin >> Q;
	for (int i = 0;i < Q;i++) {
		cin >> a >> b >> c >> d;
		x = AC[b] - AC[a - 1] + (BC[b] - BC[a - 1]) * 2;
		y = AT[d] - AT[c - 1] + (BT[d] - BT[c - 1]) * 2;
		if (x % 3 == y % 3) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}