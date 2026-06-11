#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,a[N];
inline int gcd(int x,int y) { return y?gcd(y,x%y):x; }
inline bool solve() {
	int i,odd=0,even=0;
	bool s=0;
	for (i=1;i<=n;i++)
		(a[i]&1?odd:even)++,s|=a[i]==1;
	if (s) return even&1;
	if (even&1)
		return true;
	else if (odd>=2) return false;
	else {
		even=0;
		for (i=1;i<=n;i++) even=gcd(even,a[i]-=a[i]&1);
		for (i=1;i<=n;i++) a[i]/=even;
		return !solve();
	}
}
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	if (n==1) return puts(a[1]==1?"Second":"First"),0;
	puts(solve()?"First":"Second");
	return 0;
}
