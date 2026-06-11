#include "bits/stdc++.h"
using namespace std;
int main() {
	string const Alphabet = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
	string S;
	cin >> S;
	long long N;
	cin >> N;
	vector<int>A(S.size());
	for (int i = 0; i < S.size(); i++) {
		for (int j = 0; j < 26; j++) {
			if (S.at(i) == Alphabet.at(j)) A.at(i) = j;
		}
	}
	for (int i = 0; i < S.size(); i++) {
		if (A.at(i) != 0) {
			if (N >= 26 - A.at(i)) {
				int sum = 26 - A.at(i);
				N -= sum;
				A.at(i) = 0;
			}
		}
	}
	if (N > 0){
		int const k = N % 26;
		A.at(S.size() - 1) += k;
	}
	for (int i = 0; i < S.size(); i++) {
		cout << Alphabet.at(A.at(i));
	}
	cout << endl;
}

