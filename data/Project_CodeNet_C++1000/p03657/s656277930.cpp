#include <bits/stdc++.h>
#define rep(i,n) for (long i=0;i<n;i++)
using namespace std;

int main() {
	int n,m;
	cin >> n >> m;
	cout << (n%3!=0 && m%3!=0 && (n+m)%3!=0 ? "Impossible":"Possible") << endl;
}
