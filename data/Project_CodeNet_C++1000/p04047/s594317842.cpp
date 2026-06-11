#include <bits/stdc++.h>
using namespace std;

int main(){
	int N = 0, x = 0, sum = 0;
	vector<int> len;

	cin >> N;
	for (int i = 0; i < (N * 2); i++) {
		cin >> x;
		len.push_back(x);
	}

	sort(len.begin(), len.end());

	for (; 0 < len.size(); ) {
		len.pop_back();
		sum += len.at(len.size() - 1);
		len.pop_back();
	}

	cout << sum << endl;
}