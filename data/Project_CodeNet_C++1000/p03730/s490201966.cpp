#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)

int main() {
	int a,b,c; cin >> a >> b >> c;
	int now=a;
	for(int i=0;i<=b;i++) {
		if(now%b==c) {
			cout << "YES" << endl;
			return 0;
		}
		else now+=a;
	}
	cout << "NO" << endl;
}