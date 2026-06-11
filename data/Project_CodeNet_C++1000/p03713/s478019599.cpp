#include <bits/stdc++.h>
using namespace std;

int main() {
	int H;
	int W;
	int a;
	int b;
	int H3;
	int W3;
	int H2;
	int W2;

	cin >> H >> W;

	H2=H%2;
	W2=W%2;
	H3=H%3;
	W3=W%3;

	if(H3==0){
		cout << 0 << endl;
		return 0;
	}
	if(W3==0){
		cout << 0 << endl;
		return 0;
	}
		if(W2==1){
			a=min(max(W/2+H/3+1,H/3+H/3+1),W/2+W/2+1);
		} else {
			a=W/2;
		}
		if(H2==1){
			b=min(max(H/2+W/3+1,W/3+W/3+1),H/2+H/2+1);
		} else {
			b=H/2;
		}
	cout << min(a,b) << endl;
	return 0;
}