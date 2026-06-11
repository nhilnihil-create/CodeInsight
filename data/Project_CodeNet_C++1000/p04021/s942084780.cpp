#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
typedef long long LL;

int n, a[N], b[N];
LL ans;
map <int, int> M;

int main() {
	cin>>n;
	for(int i = 1; i <= n; i++) 
		cin>>a[i], b[i] = a[i];
	sort(b + 1, b + n + 1);
	for(int i = 1; i <= n; i++)
	    M[b[i]] = i;
	for(int i = 1; i <= n; i++)
	    a[i] = M[a[i]];
	for(int i = 1; i <= n; i += 2) 
		if(a[i]%2 != i%2) ans++; 
	cout<<ans<<endl;
	return 0;
}