#include <bits/stdc++.h>
using namespace std;

long long n, t, p, c, m[100001], a[100001];
int main(){
	cin >> n >> t;
	m[0] = INT_MAX;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		m[i] = min(a[i], m[i-1]);
	}
	for(int i = 1; i <= n; i++){
		if(a[i]-m[i] > p){
			p = a[i]-m[i];
			c = 1;
		} else if(a[i]-m[i] == p) c++;
	}
	cout << c;
}