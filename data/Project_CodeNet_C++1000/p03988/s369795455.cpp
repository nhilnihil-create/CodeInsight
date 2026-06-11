#include <bits/stdc++.h>
using namespace std;

int main() {
	int N; cin >> N;
	vector<int> Q(N);
	for (int i = 0;i < N;i++) {
		cin >> Q[i];
	}
	sort(Q.begin(), Q.end());
	reverse(Q.begin(), Q.end());
	int h = Q[0]; int k;
	bool even;
	if (h % 2) {
		even = false;
		k = (h + 1) / 2;
	}
	else {
		even = true;
		k = h / 2;
	}
	int cnt = 0;
	bool j=true;
	for (int i = 0;i < N;i++) {
		if (Q[i] == h) {
			cnt++;
		}
		else {
			if (cnt < 2) {
				j = false;
				break;
			}
			h--;
			if (Q[i] != h) {
				j = false;
				break;
			}
			cnt = 1;
		}

	}
	if (h == k && j) {
		if (even) {
			if(cnt == 1)
				cout << "Possible" << endl;
			else
				cout << "Impossible" << endl;
		}
		else{
			if (cnt == 2)
				cout << "Possible" << endl;
			else
				cout << "Impossible" << endl;
		}
	}
	else {
		cout << "Impossible" << endl;
	}
}