#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	string S;
	cin >> S;
	string ansS;
	{
		int memo = 0;
		int minmemo = 0;
		for (int i = 0; i < S.size(); ++i) {
			if ('(' == S[i]) {
				memo++;
			}
			else {
				memo--;
			}
			minmemo = min(memo, minmemo);
		}
		for (int i = 0; i < (-1 * minmemo); ++i) {
			ansS += "(";
		}
		ansS += S;
	}
	{
		int memo = 0;
		for (int i = 0; i < ansS.size(); ++i) {
			if ('(' == ansS[i]) {
				memo++;
			}
			else {
				memo--;
			}
		}
		for (int i = 0; i < memo; ++i) {
			ansS += ")";
		}
	}
	cout << ansS << endl;
	return 0;
}