#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, x;
	cin >> n >> x;
	if(x == 1 || x == 2*n - 1) {
		cout << "No";
		return 0;
	}

	cout << "Yes" << '\n';
	int d = n - x; n += n-1;
	for(int i=0;i<n;i++)
		cout << (i - d + n) % n + 1 << " ";
}