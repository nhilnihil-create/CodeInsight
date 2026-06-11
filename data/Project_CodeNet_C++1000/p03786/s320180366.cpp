#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
typedef long long LL;
const LL mod = 1e9 + 7;
const int N = 3e5 + 5;

int a[N], n, l, r;

bool check(int pos) {
	LL siz = 0;
	rep(i, 1, pos)
	    siz += a[i];
	rep(i, pos + 1, n) {
		if(siz*2 < a[i]) return false;
		siz += a[i];
	}
	return true;
}

int main() {
	cin>>n;
	rep(i, 1, n) 
	    cin>>a[i];
	sort(a + 1, a + n + 1);
	l = 1, r = n;
	while(l < r) {
		int mid = (l + r)>>1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	cout<<n - l + 1<<endl;
}