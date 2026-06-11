#include <bits/stdc++.h>

using namespace std;
#define NIL -1
#define ll long long
#define MAX 100
#define pb push_back

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if(a==b&&a==c) {
		if(a%2==0) cout << -1 << endl;
		else cout << 0 << endl;
		return 0;
	}
	int cnt = 0;
	while(a%2==0 && b%2==0 && c%2==0) {
		int t1 = a/2;
		int t2 = b/2;
		int t3 = c/2;
		a = t2 + t3;
		b = t1 + t3;
		c = t1 + t2;
		cnt++;
	}
	cout << cnt << endl;
    return 0;
}
