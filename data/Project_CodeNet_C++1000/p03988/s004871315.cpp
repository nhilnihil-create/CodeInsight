#include<iostream>
using namespace std;

int main() {

	//A

	/*char st[200000];
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

	return 0;*/
	//C

	int n;
	cin >> n;

	int a[100];
	int i;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}

	int mina=101;
	for (i = 0; i < n; i++) {
		if (a[i] < mina) {
			mina = a[i];
		}
	}
	int minc = 0;
	int mincc;
	int j;
	for (i = 0; i < n; i++) {
		if (a[i] == mina) {
			minc++;
		}
	}
	if (minc >= 3) {
		cout << "Impossible";
	}
	else if (minc == 2) {
		
		for (j = mina + 1; j <= 2 * mina - 1; j++) {
			mincc = 0;
			for (i = 0; i < n; i++) {
				if (a[i] == j) {
					mincc++;
				}
			}
			if (mincc < 2) {
				cout << "Impossible";
				return 0;
			}
		}
		for (i = 0; i < n; i++) {
			if (a[i] > 2 * mina - 1) {
				cout << "Impossible";
				return 0;
			}
		}
		cout << "Possible";
		return 0;
	}else if(minc==1){
		for (j = mina + 1; j <= 2 * mina; j++) {
			mincc = 0;
			for (i = 0; i < n; i++) {
				if (a[i] == j) {
					mincc++;
				}
			}
			if (mincc < 2) {
				cout << "Impossible";
				return 0;
			}
		}
		for (i = 0; i < n; i++) {
			if (a[i] > 2 * mina) {
				cout << "Impossible";
				return 0;
			}
		}
		cout << "Possible";
		return 0;
	}


	return 0;
}