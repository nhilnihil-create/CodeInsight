#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, k; scanf("%d %d", &n, &k);

	vector<int> num;

	for (int i = 0; i < k; i++) {

		int a; scanf("%d", &a);
		num.push_back(a);

	}

	for (int i = n; i < 10 * n; i++) {

		string str = to_string(i);

		bool ok = true;

		for (char c : str)
			for (int w : num)
				if (c - '0' == w) ok = false;

		if (ok) {

			printf("%d", i);
			break;

		}

	}

	return 0;

}