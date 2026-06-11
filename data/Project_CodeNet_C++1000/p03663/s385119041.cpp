#include "bits/stdc++.h"
using namespace std;
long long cur;
bool ok;
char tmp[5];
int main(){
	cur = 1;
	ok = 0;
	for(int i = 0 ; i < 11 ; ++i){
		cout << "? " << cur << endl;
		fflush(stdout);
		cin >> tmp;
		if(tmp[0] == 'N'){
			ok = 1;
			cur /= 10;
			break;
		}
		cur *= 10;
	}
	if(!ok){
		cur = 10;
		for(int i = 0 ; i < 11 ; ++i){
			cout << "? " << cur - 1 << endl;
			fflush(stdout);
			cin >> tmp;
			if(tmp[0] == 'Y'){
				break;
			}
			cur *= 10;
		}
		cur /= 10;
	}
	else{
		long long l = cur;
		long long r = cur * 10 - 1;
		while(l < r){
			long long mid = l + r >> 1;
			cout << "? " << mid * 10 << endl;
			fflush(stdout);
			cin >> tmp;
			if(tmp[0] == 'Y'){
				r = mid;
			}
			else{
				l = mid + 1;
			}
		}
		cur = l;
	}
	cout << "! " << cur << endl;
	fflush(stdout);
}