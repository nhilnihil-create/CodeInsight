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

	for (int i = 0; i < (N * 2); i += 2) {
		sum += len.at(i);
	}

	cout << sum << endl;
}