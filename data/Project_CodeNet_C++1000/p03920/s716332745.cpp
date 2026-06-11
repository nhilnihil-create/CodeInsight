#include <bits/stdc++.h>
using namespace std;

int n, p;

int main(){
//	cin.tie(0);
//	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<n; ++i){
		if(i * (i + 1) / 2 >= n){
			p = i;
			break;
		}
	}
//	cout << " " << p << "\n";
	for(int i=1; i<=p; ++i){
		if(i == p * (p + 1) / 2 - n) continue;
		cout << i << "\n";
	}
	if(n == 1) cout << 1 << "\n";
	if(n == 2) cout << 2 << "\n";
}