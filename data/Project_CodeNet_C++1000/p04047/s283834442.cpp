#include<bits/stdc++.h>
#define pb emplace_back
using namespace std;
using ll = long long;
const int maxn = 300010;
int n, a[maxn];
signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for(int i =0 ;i < n*2;++i)
		cin >> a[i];
	sort(a, a+n*2);
	int res = 0;
	for(int i = 0;i < n*2;i += 2)
		res += a[i];
	cout << res << '\n';
}

