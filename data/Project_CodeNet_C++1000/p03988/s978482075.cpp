#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
typedef long long LL;
const LL mod = 1e9 + 7;
// head
const int maxn = 105;
int n, a[maxn], d, cnt[maxn];

int main() {
	cin>>n;
	rep(i, 1, n) cin>>a[i], d = max(a[i], d), cnt[a[i]]++;
	per(i, d, d/2 + 1) {
		if(cnt[i] < 2) {
			cout<<"Impossible"<<endl;
			return 0;
		}
		cnt[i] -= 2;
	}
	if(d%2 == 0) {
		if(cnt[d/2] != 1) {
			cout<<"Impossible"<<endl;
			return 0;
		} 
		cnt[d/2]--;
	}
	rep(i, 1, (d + 1)/2) 
	    if(cnt[i]) {
	    	cout<<"Impossible"<<endl;
	    	return 0;
	    }
	cout<<"Possible"<<endl;
}