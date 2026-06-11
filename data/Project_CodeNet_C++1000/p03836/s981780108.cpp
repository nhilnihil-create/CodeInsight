#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int sx, sy, tx, ty;
	cin>>sx>>sy>>tx>>ty;
	int x = tx - sx, y = ty - sy;
	for(int i = 0; i < y; i++){
		cout<<'U';
	}
	for(int i = 0; i < x; i++){
		cout<<'R';
	}

	for(int i = 0; i < y; i++){
		cout<<'D';
	}
	for(int i = 0; i < x; i++){
		cout<<'L';
	}

	cout<<'L';
	for(int i = 0; i < y + 1; i++){
		cout<<'U';
	}
	for(int i = 0; i < x + 1; i++){
		cout<<'R';
	}
	cout<<'D';

	cout<<'R';
	for(int i = 0; i < y + 1; i++){
		cout<<'D';
	}
	for(int i = 0; i < x + 1; i++){
		cout<<'L';
	}
	cout<<'U';
	cout<<'\n';

	return 0;
}