#include<bits/stdc++.h>
#define int long long
 
using namespace std;
int sv[16];

signed main(){
	int n;
	long long a = 0;
	char rp;
	bool br = 0;
	int dg;
	dg = 0;
	for(int i = 10; i >= 1; i--){
		cout << "? " << (int)pow(10, i) - 1 << "\n";
		fflush(stdout);
		cin >> rp;
		if(rp == 'N'){
			dg = i + 1;
			break;
		}
	}
	if(dg == 0){
		for(int i = 10; i >= 0; i--){
			cout << "? " << (int)pow(10, i) << "\n";
			fflush(stdout);
			cin >> rp;
			if(rp == 'Y' && i == 10){
				cout << "! 1\n";
				exit(0);
			}
			if(rp == 'Y'){
				dg = i + 1;
				break;
			}
		}
	}
	for(int i = 1; i < dg; i++){
		int l = 0, r = 9;
		a = a * 10;
		while(l != r){
			int mid = (l + r + 1) / 2;
			cout << "? " << a + mid << "\n";
			fflush(stdout);
			cin >> rp;
			if(rp == 'Y'){
				l = mid;
			}
			else{
				r = mid - 1;
			}
		}
		a += l;
	}
	a = a * 10;
	if(a == 0) a = 1;
	for(int i = 0; i <= 9; i++){
		cout << "? " << (a + i) * 10 << "\n";
		fflush(stdout);
		cin >> rp;
		if(rp == 'Y'){
			a = a + i;
			break;
		}
	}
	cout << "! " << a << "\n";
	fflush(stdout);
	exit(0);
	
}