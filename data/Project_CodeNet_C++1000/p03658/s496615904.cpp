#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	vector<int> L;
	for (int i = 0; i < N; i++) {
		int l;
		cin >> l;
		L.push_back(l);
	}

	sort(L.begin(), L.end(), greater<>());

	int sum = 0;
	for (int i = 0; i < K; i++) {
		//cout << L[i] << endl;
		sum = sum + L[i];
	}

	cout << sum << endl;

}