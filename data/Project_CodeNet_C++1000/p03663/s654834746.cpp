#include <iostream>

using namespace std;
int main() {
	long long sol=0;
	int a9=1;
	while(1) {
		int digmin=0;
		int digmax=9;
		if(sol==0) digmin=1;
		string res;
		while(digmin<digmax) {
			int hf=(digmin+digmax)/2;
			if(sol==0) {
				cout << "? " << sol*10+hf <<  "999999999" << endl;
			} else {
				cout << "? " << sol*10+hf <<  "99999999" << endl;
			}
			cin >> res;
			if(res[0]=='Y') {
				digmax=hf;
			} else {
				digmin=hf+1;
			}
		}
		if(digmin<9) a9=0;
		sol=sol*10+digmin;
		if(a9) {
			cout << "? " << (sol-1)*10 << endl;
			cin >> res;
			if(res[0]=='N') break;
		} else {
			cout << "? " << (sol+1) << endl;
			cin >> res;
			if(res[0]=='Y') break;
		}
	}
	cout << "! " << sol << endl;
	return 0;
}
