#include<bits/stdc++.h>
using namespace std;

const int N = 205;
typedef long long LL;

int n, a[N], ans;

int main() {
	cin>>n;
	for(int i = 1; i <= 2*n; i++)
	   cin>>a[i];
	sort(a + 1, a + 2*n + 1);
	for(int i = 1; i <= 2*n - 1; i += 2) 
	    ans += a[i];
	cout<<ans<<endl; 
	return 0;
}