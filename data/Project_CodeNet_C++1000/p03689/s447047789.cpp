#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll n,m,x,y;
	cin >> n >> m >> x >> y;
	int P = 999999999;
	int N = -(P+1);
	if(n%x == 0 && m%y == 0) {
		cout << "No\n";
	} else {
		cout << "Yes\n";
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(j > 0) {cout << " ";}
				if(i%x == 0 && j%y == 0) {
					cout << P;
				} else if(i%x == x-1 && j%y == y-1) {
					cout << N;
				} else {
					cout << 0;
				}
			}
			cout << '\n';
		}
	}
}
