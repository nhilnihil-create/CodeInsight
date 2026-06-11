#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	if(n==1) {
		cout << 1 << endl;
	}
	if(n>=2 && n<=3) {
		cout << 2 << endl;
	}
	if(n>=4 && n<=7) {
		cout << 4 << endl;
	}
	if(n>=8 && n<=15) {
		cout << 8 << endl;
	}
	if(n>=16 && n<=31) {
		cout << 16 << endl;
	}
	if(n>=32 && n<=63) {
		cout << 32 << endl;
	}
	if(n>=64 && n<=100) {
		cout << 64 << endl;
	}
}
