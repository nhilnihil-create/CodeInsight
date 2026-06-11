#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << # x << "; "<< x << endl


int main() {
	string S;
	int N;
	cin >> N >> S;
	int x = 0;
	vector<int> data{0};
	vector<string> vec(N);
	for (int i = 0; i < N; i++) {
		vec.at(i) = S.at(i);
	}
	for (int j = 0; j < N; j++) {
		if (vec.at(j) == "I") {
			x++;
			data.push_back(x);
		}
		else if (vec.at(j) == "D") {
			x--;
			data.push_back(x);
		}
	}
	sort(data.begin(), data.end());
	cout << data.at(N) << endl;
}