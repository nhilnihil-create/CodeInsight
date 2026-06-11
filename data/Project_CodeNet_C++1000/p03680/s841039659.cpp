#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> Button(N);
	for (int i = 0; i < N; i++) {
		int z;
		cin >> z;
		--z;
		Button.at(i) = z;
	}
    
	//入力層終わり
	int cnt = 0;
	int tmp = 0;

	for (;;) {
		if (tmp == 1) {
			cout << cnt << endl;
			break;
		}

		if (cnt >= N) {
			cout << "-1" << endl;
			break;
		}
		tmp = Button.at(tmp);
		++cnt;
	}

	return 0;
}
