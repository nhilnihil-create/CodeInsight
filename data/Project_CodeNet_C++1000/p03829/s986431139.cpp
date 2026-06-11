#include <bits/stdc++.h>
using namespace std;

long long n, a, b, t, x[100000];
int main(){
	cin >> n >> a >> b;
	for(int i = 0; i < n; i++) cin >> x[i];
	for(int i = 1; i < n; i++){
		if((x[i]-x[i-1])*a < b) t += (x[i]-x[i-1])*a;
		else t += b;
	}
	cout << t;
}