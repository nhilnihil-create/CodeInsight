#include<iostream>
#include<vector>
using namespace std;
long long n, v, w; vector<int>C;
int main() {
	cin >> n;
	for (int i = 0; i < 60; i++) {
		if (n < ((1LL << i) - 1)) {
			for (int j = 1; j <= i - 1; j++)C.push_back(j);
			for (int j = 1; j <= i - 1; j++)C.push_back(j);
			n -= (1LL << (i - 1)) - 1; v = i - 1; w = i - 1; break;
		}
	}
	for (int i = v; i >= 0; i--) {
		if (n >= (1LL << i)) {
			vector<int>D;
			for (int j = 0; j < C.size() - i; j++)D.push_back(C[j]);
			w++; D.push_back(w);
			for (int j = C.size() - i; j < C.size(); j++)D.push_back(C[j]);
			D.push_back(w);
			n -= (1LL << i);
			C = D;
		}
	}
	cout << C.size() << endl;
	for (int i = 0; i < C.size(); i++) { if (i)cout << ' '; cout << C[i]; }cout << endl;
	return 0;
}