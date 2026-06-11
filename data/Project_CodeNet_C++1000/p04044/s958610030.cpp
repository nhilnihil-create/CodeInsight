#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, L;
	cin >> N >> L;
	vector<string> s(N);

	for (int i = 0; i < N; ++i) {
		string str;
		cin >> str;
		s[i] = str.substr(0, L);
	}

	sort(s.begin(), s.end());
	
	for (int i = 0; i < N; ++i) cout << s[i];
	cout << endl;
}