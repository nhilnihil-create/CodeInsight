#include<bits/stdc++.h>
using namespace std;
const int maxn = 1<<20;
int n, a[maxn], x[maxn], y[maxn];
int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) x[i] = y[i] = 1;
	for(int i = n; i; i--) {
		int t = n-i+1;
		x[a[i]+1]+=t, y[a[i]-1]+=t;
	}
	for(int i = 1; i <= n; i++) x[i] += x[i-1];
	for(int i = n; i; i--) y[i] += y[i+1];
	for(int j = 1; j <= n; j++) cout << x[j] << " "; cout << '\n';
	for(int i = 1; i <= n; i++) cout << y[i] << " ";
}
