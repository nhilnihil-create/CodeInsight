#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 123;
int n, m, kol[N];

int main(){
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int l, r;
		cin >> l >> r;
		kol[l]++;
		kol[r]++;
	}
	for(int i = 1; i <= n; i++){
		if(kol[i] % 2 == 1){
			cout << "NO";
			exit(0);
		}
	}
	cout << "YES";
}