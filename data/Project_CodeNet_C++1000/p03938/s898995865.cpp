#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e4 + 7;
int t = 20001;
int p[N], a[N], b[N];
int n; 
 
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> p[i]; 
	} 
	for (int i = 1; i <= n; i++) {
 		a[i] = i * 2 * t;
		b[i] = (n - i + 1) * 2 * t; 
	} 
	for (int i = 2; i <= n; i++) {
		b[p[i]] += i;
	}
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << endl;
	for (int i = 1; i <= n; i++)
		cout << b[i] << " ";	
		
 
}	