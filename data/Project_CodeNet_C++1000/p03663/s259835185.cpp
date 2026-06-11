#include<bits/stdc++.h>
#define int long long
using namespace std;
 
signed main(){
	int n;
	int x = 0;
	char a;
	int dem=0;
	for(int i = 10; i >= 1; i--){
		cout << "? " << (int)pow(10, i) - 1 << "\n";
		fflush(stdout);
		cin >> a;
		if(a == 'N'){
			dem = i + 1;
			break;
		}
	}
	if(dem == 0){
		for(int i = 10; i >= 0; i--){
			cout << "? " << (int)pow(10, i) << "\n";
			fflush(stdout);
			cin >> a;
			if(a == 'Y' && i == 10){
				cout << "! 1\n";
				exit(0);
			}
			if(a == 'Y'){
				dem = i + 1;
				break;
			}
		}
	}
	for(int i = 1; i < dem; i++){
		int l = 0, r = 9;
		x = x * 10;
		while(l != r){
			int mid = (l + r + 1) / 2;
			cout << "? " << x + mid << "\n";
			fflush(stdout);
			cin >> a;
			if(a == 'Y'){
				l = mid;
			}
			else{
				r = mid - 1;
			}
		}
		x += l;
	}
	x = x * 10;
	if(x == 0) x = 1;
	for(int i = 0; i <= 9; i++){
		cout << "? " << (x + i) * 10 << "\n";
		fflush(stdout);
		cin >> a;
		if(a == 'Y'){
			x = x + i;
			break;
		}
	}
	cout << "! " << x << "\n";
	fflush(stdout);}