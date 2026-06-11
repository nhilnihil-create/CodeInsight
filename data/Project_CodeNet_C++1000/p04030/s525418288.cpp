#include "bits/stdc++.h"
using namespace std;

int main() {
	string S;
	cin >> S;
	string ansS;
	for (int i = 0;i<S.size();++i) {
		if ('0' ==S[i]) {
			ansS += "0";
		}
		else if ('1' == S[i]) {
			ansS += "1";
		}
		else {
			if (ansS.size() >0) {
				ansS.erase(ansS.size()-1);
			}
		}
	}
	cout << ansS<<endl;
	return 0;
}