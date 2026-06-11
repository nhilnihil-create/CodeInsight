#include <bits/stdc++.h>
#include <string>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<string> avoid;
	for (int i = 0; i < k; i++) {
		string digit;
		cin >> digit;
		avoid.push_back(digit);
	}

	while (true) {
		//convert integer to string
		//cout << "n = " << n << endl;
		string nstring = to_string(n);		//having this here means 
		int i = 0;
		for (; i < k; i++) {
			if (nstring.find(avoid.at(i)) != string::npos) {	//have to do npos!
				n++;
				//nstring = to_string(n);		//we have to reset this
				break;
			}
		}
		if (i == k) {
			cout << n << endl;
			return 0;
		}

	} 
}