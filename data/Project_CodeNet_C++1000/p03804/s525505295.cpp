#include <bits/stdc++.h>
#define PI 3.14159265359
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<string> v1(N), v2(M);
	for (int i = 0; i < N; i++) {
		cin >> v1.at(i);
	}
	for (int i = 0; i < M; i++) {
		cin >> v2.at(i);
	}

	bool b = false;
	for (int i = 0; i <= N - M; i++) {
		for (int j = 0; j <= N - M; j++) {
			string s = v1.at(i).substr(j, M);

			if (s==v2.at(0)) {
				int f = 1;
				for (int k = 1; k < M; k++) {
					s = v1.at(i+k).substr(j, M);
					if (s != v2.at(k)) {
						f = 0;
						break;
					}
				}

				if (f) {
					b = true;
					break;
				}
			}
		}

		if (b) break;
	}

	if (b) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}