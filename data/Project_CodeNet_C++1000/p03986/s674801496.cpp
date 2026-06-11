#include<iostream>
using namespace std;

int main() {

	//A

	char st[200000];
	int i;
	for (i = 0; i < 200000; i++) {
		st[i] = ' ';
	}
	cin >> st;
	int stcount,delcount;
	stcount = 0;
	delcount = 0;
	for (i = 0; i < 200000; i++) {
		if (st[i] == 'T') {
			if (delcount == 0) {
				stcount++;
			}
			else {
				delcount--;
			}
		}else if(st[i] =='S'){
			delcount++;
		}
	}
	cout << stcount * 2;

	return 0;
}