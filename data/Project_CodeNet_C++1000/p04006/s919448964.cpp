#include<bits/stdc++.h>
using namespace std;

const int N = 4e3 + 5;
typedef long long LL;

int n;
LL x, ans, a[N], b[N];

int main() {
	cin>>n>>x;
	for(int i = 1; i <= n; i++)
		cin>>a[i], ans += a[i], b[i] = a[i];
	for(int i = 1; i < n; i++) {
		LL res = i*x;
		for(int j = 1; j <= n; j++)
		    b[j] = min(b[j], a[j - i + ((j - i) <= 0 ? n:0)]), res += b[j];
		ans = min(ans, res); 
	}
	cout<<ans<<endl;
}

