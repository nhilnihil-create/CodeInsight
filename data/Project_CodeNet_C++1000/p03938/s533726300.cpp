#include<bits/stdc++.h>
using namespace std;

#define LL long long
int a[20005], b[20005], k;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n; cin >> n;
	for(int i=1;i<=n;i++) {
		cin >> k;
		a[k] = i, b[k] = i;
	}

	for(int i=1;i<=n;i++) {
		a[i] += i * n;
		b[i] += n * (n - i);
	}

	for(int i=1;i<=n;i++) cout << a[i] << " ";
	cout << '\n';
	for(int i=1;i<=n;i++) cout << b[i] << " ";
}