#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string S, T;

int sum1[100000 * 2 + 1000], sum2[100000 * 2 + 1000];

int main() {
	cin >> S >> T;
	int q;
	cin >> q;
	for (int i = 0; i < S.size(); i++) {
		sum1[i + 1] = sum1[i] + (S[i] == 'A' ? 1 : 2);
	}
	for (int i = 0; i < T.size(); i++) {
		sum2[i + 1] = sum2[i] + (T[i] == 'A' ? 1 : 2);
	}
	for (int i = 0; i < q; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a--, c--;
		if ((sum1[b] - sum1[a]) % 3 == (sum2[d] - sum2[c]) % 3) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

	return 0;
}