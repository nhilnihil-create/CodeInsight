#include<bits/stdc++.h>

using namespace std;

long long n,ans = 0;
long long a[200005],b[200005];

int main(){
	cin >> n;
	for(int i = 1;i <= n;i ++)
		cin >> a[i], b[i] = a[i];
	sort(b + 1,b + 1 + n);
	for(int i = 1; i <= n; ++i) 
		a[i] = lower_bound(b + 1,b + 1 + n,a[i]) - b;
	for(int i = 1; i <= n; ++i) 
		if((a[i] & 1) ^ (i & 1)) ans++;
	cout << (ans >> 1) << endl;
	return 0;
}