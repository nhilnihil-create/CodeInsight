#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << # x << "; "<< x << endl


int main() {
	int N, K, l;
	cin >> N >> K;
	vector<int> vec;
	int total = 0;
	for (int i = 0; i < N; i++) {
		cin >> l;
		vec.push_back(l);
	}
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	for (int j = 0; j < K; j++) {
		total += vec.at(j);
	}
	cout << total << endl;
}