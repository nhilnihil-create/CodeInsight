#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++);

int main() {
	int N, K;
	int temp = 0;
	cin >> N >> K;
	
	vector<int> xn(N);
	for (int i = 0; i < N; i++) {
		cin >> xn.at(i);
	}
	for (int i = 0; i < N; i++) {
		int pos = xn.at(i);
		int atype = pos*2;
		int btype = abs(K - pos)*2;
		temp += min(atype, btype);
	}
	cout << temp << endl;
}
