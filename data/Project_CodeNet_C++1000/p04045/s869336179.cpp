#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	long long N, K; cin >> N >> K;
	vector<char>D(K);
	for (long long i = 0; i < K; i++) {
		cin >> D.at(i);
	}
	for (long long i = N; i < 100000; i++) {
		string S = to_string(i);
		bool check = true;
		for (long long j = 0; j < S.size(); j++) {
			for (long long k = 0; k < K; k++) {
				if (S.at(j) == D.at(k)) check = false;
			}
		}
		if (check) {
			cout << S << endl;
			return 0;
		}
	}
}
