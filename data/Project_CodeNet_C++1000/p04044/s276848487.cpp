#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
	int N, L; cin >> N >> L;
	vector<string> a(N);

	for (int i = 0; i < a.size(); i++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	for(int i = 0; i < a.size(); i++) {
		cout << a[i];
	}

	return 0;
}
