#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 12;
int a[N], n, ans;

int main(){
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	for (int i = 0; i < n; i++)
		if(a[i] == i + 1){
			swap(a[i], a[i + 1]);
			ans++;
		}
	
	cout << ans;
}